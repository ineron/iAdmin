//
//  NavPanel.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 15.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>
#include <apps/NavPanel.h>
#include <data/admin/nav.h>
#include <cppcms/url_dispatcher.h>
#include <cppdb/frontend.h>


//#include <boost/uuid/uuid.hpp>
//#include <boost/uuid/uuid_io.hpp>
//#include <boost/uuid/uuid_generators.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>

// todo
// Полчить список баз  и вывести по синонимам организаций

namespace apps{
    NavPanel::NavPanel(cppcms::service &srv):Master(srv)
    {
        //dispatcher().assign("/?",&NavPanel::prepare,this);
        //mapper().assign(""); // default empty url
        //__DEBUGLINE__;
    }
    NavPanel::~NavPanel()
    {
        
    }
    void NavPanel::prepare()
    {
        std::string uid=NULL_UID;
        //cppdb::transaction tr(m_session);
        cppdb::result result;
        cppcms::json::value object;
        __DEBUGLINE__;
        //if(session().is_set("loginlevel")){
        //
        //    if (session().is_set("uid")) {
        //        uid = session().get("uid");
        //    }
        //}
        __DEBUGLINE__;
        // Проверим бадже для сообщений
        // TODO передалать вызов баджей в аякс вызов события
        /*
        std::string query;
        query = INLINE_SQLSCRIPT
        (
         select sum(inbox),sum(allmsg) from
         (
          select count(1) inbox,0 allmsg from messages where state = 0 and author_ref = ?
          union all
          select 0 inbox,count(1) allmsg from messages where author_ref = ?
          )a
         );
        result = sql() << query << uid << uid << cppdb::row;
        if (!result.empty()) {
            tmpl.newMsgCount = result.get<int>(0);
        }
        */
        // Получаем структуру меню
        std::string menuquery = INLINE_SQLSCRIPT
        (
            select row_to_json(t) from (
            SELECT array_to_json(array_agg(row_to_json(t))) records FROM(
                SELECT ref, parent_ref, order_id, level_id, name,
                href, link_type, CASE WHEN icon is null THEN '' ELSE icon END icon,case when badge is null then '' else badge end badge,0 acl,
                    (SELECT array_to_json(array_agg(row_to_json(t))) from (SELECT ref, parent_ref, order_id, level_id, name,href, link_type, CASE WHEN icon is null THEN '' ELSE icon END icon,case when badge is null then '' else badge end badge,0 acl
                    FROM global.nav_items where parent_ref = n2.ref)t) subitems
                FROM global.nav_items n2 where level_id=0 order by order_id) t
            ) as t
         
         );
        
        result = sql() << menuquery << cppdb::row;
        if (!result.empty()) {
            std::stringstream stream;
            std::string json = result.get<std::string>(0);
            boost::replace_all(json,"null","[]");
            stream<<json;
            object.load(stream,true);
            std::cout<<object<<std::endl;
        }
        
        if (!object.is_undefined()) {
            cppcms::json::array records = object["records"].array();
            for(auto i = records.begin();i!=records.end();i++) {
                data::admin::NavItem item;
                item.url = (*i)["href"].str();
                item.title = (*i)["name"].str();
                item.icon = (*i)["icon"].str();
                item.style = "menu-item-parent";
                if(!(*i)["subitems"].is_null()){
                    std::cout<<(*i)["subitems"]<<std::endl;
                    cppcms::json::array subitems = (*i)["subitems"].array();
                    for (auto s=subitems.begin(); s!=subitems.end(); s++) {
                        data::admin::NavItem sitem;
                        sitem.url = (*s)["href"].str();
                        sitem.title = (*s)["name"].str();
                        sitem.icon = (*s)["icon"].str();
                        sitem.style = "menu-item-parent";
                        item.child.push_back(sitem);
                    }
                }
                m_itemList.push_back(item);
            }
        }
    }
    void NavPanel::main(std::string path)
    {
        __DEBUGLINE__;
        prepare();
    }
    data::admin::NavItemsList NavPanel::getDate()
    {
        __DEBUGLINE__;
        prepare();
        return m_itemList;
    }
}