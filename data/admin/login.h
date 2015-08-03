#ifndef TMPL_LOGIN_H
#define TMPL_LOGIN_H
#include "master.h"
#include <cppcms/view.h>
#include <cppcms/form.h>

namespace data {
namespace admin{
    
    
    struct LoginForm : public cppcms::form {
        cppcms::widgets::text email;
        cppcms::widgets::hidden formId;
        cppcms::widgets::password password;
        cppcms::widgets::checkbox remember;
        cppcms::widgets::submit submit;
        //cppcms::widgets::button cancel;
        
        LoginForm()
        {
            formId.value("1234");
            email.message(booster::locale::translate("Email"));
            email.non_empty();
            password.message(booster::locale::translate("Password"));
            password.non_empty();
            remember.message(booster::locale::translate("Remeber me"));

            submit.message(booster::locale::gettext("Login"));
            submit.value(booster::locale::translate("Login"));
            //cancel.message(booster::locale::gettext("Отмена"));
            //cancel.value("cancel");
            //*this & email & password & remember & submit;
	    add(email);
	    add(password);
	    add(remember);
        }
        virtual bool validate()
        {
            if(!form::validate())
                return false;
            return true;
        }
    };
    
    /*struct LoginForm{
	void load(cppcms::http::context &cont){};
	bool validate(){ return true; };
    };*/
    //-------------------------------------------------------------------------------------
    // Dsc: Форма авторизации
    //-------------------------------------------------------------------------------------
    struct login :public data::admin::master{
        LoginForm loginForm;
        //-------------------------------------------------------------------------------------
        // Dsc:
        //-------------------------------------------------------------------------------------
        //bool is_signin;
        //std::string email,password;
        //bool remember;
        //-------------------------------------------------------------------------------------
        // Dsc: Конструктор страницы
        //-------------------------------------------------------------------------------------
        //login(){};//:apps::data::basic_master()
        //~login(){}
    };


    struct Logout :public cppcms::base_content{
        Logout(){};
        ~Logout(){}
    };
    
}}


#endif // TMPL_LOGIN_H
