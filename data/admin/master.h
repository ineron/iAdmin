#ifndef TMPL_MASTER_H
#define TMPL_MASTER_H
#pragma once
#include <data/admin/nav.h>
#include <cppcms/view.h>
#include <booster/function.h>
#include <cppcms/serialization.h>

namespace cppcms {
	namespace json {
		class value;
	}
}

namespace data {
    namespace admin{
	struct general_info : public cppcms::serializable {
		std::string blog_title;
		std::string blog_description;
		std::string contact;
		std::string copyright_string;

		void serialize(cppcms::archive &a)
		{
			a & blog_title & blog_description & contact & copyright_string;
		}
	};
	struct form_details
	{
	
	};
	struct form_widgets
	{
	
	};

	struct _OPTION{
	    std::string value;
	    std::string selected;
	    std::string desabled;
	    std::string text;
	};
        
        typedef struct _SECTION{
            int type=1;
            std::string headline="col col-6";
            std::string placeholder;
            std::string id;
            std::string name;
            std::string icons;
            std::string tooltip;
            std::string text;
            int desabled;
            std::vector<_OPTION>options;

        }FormSection;;
        
        
        typedef struct _FOOTERCONTENT{
    	    std::string content;
        }FooterContent;;
        
        typedef struct _FORMCONTENT{
    	    std::string header;
    	    std::string form_class="smart-form";
    	    int is_smart;
    	    int is_plugins;
    	    std::vector<_SECTION>sections;
    	    std::vector<_FOOTERCONTENT>footer;
        }FormContent;        

	//typedef std::vector<_FORMCONTENT>FormContent;
	
	struct widget_set
	{
	    std::string headlines="col-sm-12 col-md-12 col-lg-12";
	    std::string widget_icon;
	    std::string widget_name;
	    std::string widget_id;
	    //std::string content;// отрендереный контент блока или див идентификатором ресурса для загрузки
	    FormContent content;
	};
	
	struct widget_group
	{
	    std::vector<widget_set>widgets;
	};
	
	
	typedef std::vector<widget_group>WidgetGroup;
	
	struct basic_master :public cppcms::base_content {
		general_info info;
		std::string media;
		std::string host;
		std::string cookie_prefix;
		booster::function<std::string(std::string const &)> markdown2html;
		booster::function<std::string(std::string const &)> xss;
    		std::string (*latex)(std::string const &);
		NavItemsList navItems;
	};
	struct master:public data::admin::basic_master{
	    
	};
	struct base_content:public data::admin::master{
	    
	};
	struct content:public data::admin::base_content{
	    
	};
	struct page:public data::admin::content{
	    WidgetGroup widget_group;
	};

	void init_tex_filer(cppcms::json::value const &v);
    }
}

#endif //TMP_MASTER_H

