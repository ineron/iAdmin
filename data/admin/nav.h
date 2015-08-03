#ifndef TMPL_NAV_H
#define TMPL_NAV_H

#include <apps/defines.h>

#include <cppcms/view.h>
#include <booster/function.h>
#include <cppcms/serialization.h>

#include <iostream>

namespace data {
    namespace admin{
        struct _NAVITEM;
        //typedef std::vector<_NAVITEM> NavItemsList;
        
        typedef struct _NAVITEMLIST : public std::vector<_NAVITEM> , public cppcms::serializable {
        
        public:
            void serialize(cppcms::archive &archive) {
                //std::cout << "in serialize" << std::endl;
                if (archive.mode() == cppcms::archive::save_to_archive) {
                    cppcms::archive_traits<std::vector<_NAVITEM> >::save(*this,archive);
                } else {
                    cppcms::archive_traits<std::vector<_NAVITEM> >::load(*this,archive);
                }
            }  
            
        }NavItemsList;
    }
}
/*
namespace cppcms {
    template<>
    struct serialization_traits<data::admin::_NAVITEM > {
        static void load(std::string const &serialized_object,data::admin::NavItemsList &real_object)
        {
            std::stringstream ss(serialized_object);
        }
        static void save(data::admin::NavItemsList const &real_object,std::string &serialized_object)
        {
            std::stringstream ss;
            
        }
    };
};
*/
namespace data {
    namespace admin{
        
        //struct _NAVITEM;
        
        //typedef std::vector<_NAVITEM> NavItemsList;
        
        typedef struct _NAVITEM : public cppcms::serializable {
            std::string url;
            std::string title;
            std::string style;
            std::string icon;
            std::string badge;
            NavItemsList child;
            
            void serialize(cppcms::archive &a)
            {
                //std::cout << "in serialize _NAVITEM" << std::endl;
                a & url & title & style & icon & badge & child;
            }
            
        }NavItem;
        
        struct nav_panel :public cppcms::base_content
        {
            //NavItemsList navItems;   // список выводимых пунктов меню (url,desc)
        };
    }
}

namespace cppcms {
    namespace json {
        template<>
        struct traits<data::admin::NavItem> {
            static data::admin::NavItem get(value const &v)
            {
                data::admin::NavItem c;
                if(v.type()!=is_object)
                    throw bad_value_cast();
                
                c.url      = v.get<std::string>("href");
                c.title    = v.get<std::string>("name");
                c.style    = v.get<std::string>("style");
                c.icon     = v.get<std::string>("icon");
                c.badge    = v.get<std::string>("badge");// javascript procedure
               
                c.child    = v.get<data::admin::NavItemsList>("child");
                
                return c;
            }
            
            static void set(value &v,data::admin::NavItem const &inv){
                v.set("href",inv.url);
                v.set("name",inv.title);
                v.set("style",inv.style);
                v.set("icon",inv.icon);
                v.set("badge",inv.badge);
                v.set("child",inv.child);
                
                
            }
        };

        template<>
        struct traits<data::admin::NavItemsList> {
            static data::admin::NavItemsList get(value const &v)
            {
                
                data::admin::NavItemsList c;
                if(v.type()!=is_array)
                    throw bad_value_cast();
                
                json::array const &a=v.array();
                c.resize(a.size());
                __DEBUGLINE__;
                std::cout<<a.size()<<std::endl;
                for(unsigned i=0;i<a.size();i++){
                    __DEBUGLINE__;
                    std::cout<<a[i].get_value<data::admin::NavItem>()<<std::endl;
                    c[i]=a[i].get_value<data::admin::NavItem>();}
                __DEBUGLINE__;
                return c;
            }
            
            static void set(value &v,data::admin::NavItemsList const &inv){

                v=json::array();
                json::array &a=v.array();
                a.resize(inv.size());
                for(unsigned i=0;i<inv.size();i++)
                    a[i].set_value(inv[i]);
                
                
                
            }
        };
    
    }
}


#endif //TMP_NAV_H