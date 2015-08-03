#pragma once
#include <cppcms/application.h>
#include <data/admin/master.h>
#include <apps/defines.h>

namespace cppdb {
	class session;
}
namespace data {
	struct basic_master;
}
namespace apps {
	class database_is_not_configured_error : public std::runtime_error {
	public:
		database_is_not_configured_error() : 
			std::runtime_error("The database was not configured")
		{
		}
	};

	class database_version_error : public std::runtime_error {
	public:
		database_version_error() :
			std::runtime_error("Invalid database version")
		{
            
		}
	};


	class BasicMaster : public cppcms::application {
	public:
		BasicMaster(cppcms::service &s);
		~BasicMaster();
		
		virtual void clear();
	protected:
		std::string host_;
		cppdb::session &sql();
        void prepare(data::admin::basic_master &);
        void prepare_nav(data::admin::basic_master &);
	private:
		std::auto_ptr<cppdb::session> sql_;
		std::string conn_str_;
		std::string media_;
		std::string cookie_;
        //data::admin::NavItemsList m_itemList;
	};
	
	void init_tex_filer(cppcms::json::value const &s);
}

