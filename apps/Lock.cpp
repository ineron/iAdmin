//
//  Lock.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/Lock.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    Lock::Lock(cppcms::service &srv):Master(srv)
    {
        dispatcher().assign("/?",&Lock::prepare,this);
        mapper().assign(""); // default empty url
    }
    Lock::~Lock()
    {
    
    }
    void Lock::prepare()
    {
    
    }

}