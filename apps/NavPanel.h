//
//  NavPanel.h
//  iAdmin
//
//  Created by Евгений Илюшин on 15.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__NavPanel__
#define __iAdmin__NavPanel__

#include <apps/Master.h>

namespace apps {
    class NavPanel:public Master
    {
        data::admin::NavItemsList m_itemList;
    public:
        NavPanel(cppcms::service &srv);
        virtual ~NavPanel();
        data::admin::NavItemsList getDate();
    protected:
        virtual void prepare();
        virtual void main(std::string path);
    };
}
#endif /* defined(__iAdmin__NavPanel__) */
