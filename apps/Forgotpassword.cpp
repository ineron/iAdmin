//
//  Forgotpassword.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 13.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/Forgotpassword.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    
    Forgotpassword::Forgotpassword(cppcms::service &srv):Master(srv)
    {
        dispatcher().assign("/?",&Forgotpassword::prepare,this);
        mapper().assign(""); // default empty url
        
    }
    Forgotpassword::~Forgotpassword()
    {
        
    }
    void Forgotpassword::prepare()
    {
        
    }
    
    
}