//
//  Login.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/Login.h>
#include <data/admin/login.h>
#include <apps/auth/HashFunction.h>

#include <cppcms/application.h>
#include <cppcms/session_interface.h>
#include <cppcms/url_dispatcher.h>
#include <cppdb/frontend.h>
#include <cppcms/http_response.h>
/*
#include <cppcms/json.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>
#include <cppcms/http_file.h>
#include <cppcms/url_mapper.h>
*/
namespace apps{
    Login::Login(cppcms::service &srv):Master(srv)
    {
        dispatcher().assign("/?",&Login::prepare,this);
        mapper().assign(""); // default empty url
    }
    Login::~Login()
    {
        
    }
    void Login::prepare()
    {
        
        data::admin::login tmpl;
        
        Master::session().reset_session();
        Master::session().clear();
        std::cout<<request().request_method()<<std::endl;
        std::cout<<"is set uid "<<application::session().is_set("uid")<<std::endl;
        
        if(request().request_method()=="POST") {
            tmpl.loginForm.load(context());
            if(!tmpl.loginForm.validate()) {
                tmpl.loginForm.password.clear();
            } else {
                cppdb::result result;
                cppdb::result loginLevelRes;
                result = sql() << "select password_hash,password_method,password_salt,user_ref, (crypt(?,'$1$'||password_salt)=password_hash)::int passwd_valid,auth_info.id,time_to_string(last_login_attempt) lastlogin from auth_identity  inner join auth_info on auth_identity.auth_info_id = auth_info.id where \"identity\" = ? "<<tmpl.loginForm.password.value()<<tmpl.loginForm.email.value()<<cppdb::row;
                
                std::cout<< tmpl.loginForm.email.value()<<std::endl;
                if(!result.empty())
                {
                    std::cout<<result.get<std::string>("password_method")<<std::endl;
                    std::cout<<result.get<std::string>("passwd_valid")<<std::endl;
                    
                    auth::HashFunction *crypt;
                    if(result.get<std::string>("password_method") == "crypt") //md5
                    {
                        std::cout<<"method crypt "<<std::endl;
                        if(result.get<int>("passwd_valid"))
                        {
                            
                            loginLevelRes = sql()<<"select role from \"user\" where ref = ?"<<result.get<std::string>("user_ref")<<cppdb::row;
                            if (!loginLevelRes.empty()) {
                                Master::session().set("loginlevel",loginLevelRes.get<int>("role"));
                            }
                        }
                    }
                    else //bcrypt
                    {
                        std::cout<<"method bcrypt "<<std::endl;
                        crypt = new auth::BCryptHashFunction(7);
                        if(crypt->verify(tmpl.loginForm.password.value(), result.get<std::string>("password_hash"), result.get<std::string>("password_salt")))
                        {
                            std::cout<<__LINE__<<std::endl;
                            loginLevelRes = sql()<<"select role from \"user\" where ref = ?"<<result.get<std::string>("user_ref")<<cppdb::row;
                            if (!loginLevelRes.empty()) {
                                Master::session().set("loginlevel",loginLevelRes.get<int>("role"));
                            }
                            
                        }
                    }
                
                }
                if (application::session().is_set("loginlevel"))
                {
                    std::string uid=result.get<std::string>("user_ref");
                    std::string lastLogin = result.get<std::string>("lastlogin");
                    
                    std::cout<<Master::session().get("loginlevel")<<" "<<__LINE__<<std::endl;
                    
                    std::cout<<lastLogin<<std::endl;
                    Master::session().set("lastlogin",lastLogin);
                    sql()<<"update auth_info set last_login_attempt = now() where id=? "<<result.get<int>("id")<<cppdb::exec;
                    
                    Master::session().set("uid",uid);
                    Master::session().expose("uid");
                    Master::session().save();
                    
                    std::cout<<"uid "<<application::session().get("uid")<<" "<<__LINE__<<std::endl;
                    response().set_redirect_header(url("/dashboard"));
                    return;
                }


                tmpl.loginForm.password.clear();
                tmpl.loginForm.password.valid(false);
                tmpl.loginForm.email.valid(false);
                }
            }
        
        
        render("login", tmpl);
        
    }

}