/*
 * Copyright (C) 2011 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include "HashFunction.h"
#include "AuthUtils.h"

/*
 #ifndef WT_TARGET_JAVA
 // for htonl():
 #ifndef WT_WIN32
 #include <arpa/inet.h>
 #else
 #include <winsock2.h>
 #endif
 #endif
 */
#include <cstring>
#include <cstdio>
#include <stdexcept>

extern "C" {
#include "bcrypt/ow-crypt.h"
}

#include "md5/md5.h"
//#include <openssl/des.h>
//#include <openssl/crypto.h>

namespace apps {
    namespace auth {
        
        HashFunction::~HashFunction()
        { }
        
        bool HashFunction::verify(const std::string& msg,
                                  const std::string& salt,
                                  const std::string& hash) const
        {
            return compute(msg, salt) == hash;
        }
        
        
        std::string MD5HashFunction::compute(const std::string& msg,
                                             const std::string& salt) const
        {
            std::string md5Salt = "$1$" + salt;
            return crypt(msg.c_str(),md5Salt.c_str());
        }
        
        bool MD5HashFunction::verify(const std::string& msg,
                                     const std::string& salt,
                                     const std::string& hash) const
        {
            //std::string md5Salt = "$1$" + salt;
            return compute(msg,salt) == hash;
        }
        
        std::string MD5HashFunction::name() const
        {
            return "MD5";
        }
        
        BCryptHashFunction::BCryptHashFunction(int count)
        : count_(count)
        { }
        
        std::string BCryptHashFunction::compute(const std::string& msg,
                                                const std::string& salt) const
        {
            
            //#ifdef __APPLE__
            
            char setting[32];
            char c_salt[16];
            std::strncpy(c_salt, salt.c_str(), 16);
            if (salt.length() < 16)
                std::memset(c_salt + salt.length(), 'A', 16 - salt.length());
            
            if (!crypt_gensalt_rn("$2y$", count_, c_salt, 16, setting, 32)) {
                std::perror("crypt_gen_salt_rn");
                throw std::runtime_error("bcrypt() gensalt internal error");
            } else {
                char result[64];
                std::cout<<"setting "<<setting<<std::endl;
                if (!crypt_rn(msg.c_str(), setting, result, 64)) {
                    std::perror("crypt_rn");
                    throw std::runtime_error("bcrypt() internal error");
                }
                return result;
            }
            
            //#else
            //    std::string md5Salt = "$1$" + salt;
            //    return crypt(msg.c_str(), md5Salt.c_str());
            //#endif
        }
        
        bool BCryptHashFunction::verify(const std::string& msg,
                                        const std::string& hash,
                                        const std::string& salt) const
        {
            //#ifdef __APPLE__
            char result[64];
            if (!crypt_rn(msg.c_str(), hash.c_str(), result, 64)) {
                std::perror("crypt_rn");
                throw std::runtime_error("bcrypt() internal error");
            }
            std::cout<<"msg "<<msg<<" hash "<<hash<<" salt "<<salt<<std::endl;
            std::cout<<"crypt "<<result<<std::endl;
            
            std::cout<<compute(msg,salt)<<std::endl;
            
            return result == hash;
            //#else
            //std::cout<<"msg "<<msg<<" hash "<<hash<<" salt "<<salt<<std::endl;
            //std::cout<<"crypt "<<crypt(msg.c_str(), salt.c_str())<<std::endl;
            //std::cout<<"crypt "<<crypt(msg.c_str(), hash.c_str())<<std::endl;
            //return crypt(msg.c_str(), std::string("$2y$"+salt).c_str()) == hash;
            //#endif
        }
        
        std::string BCryptHashFunction::name() const
        {
            return "bcrypt"; 
        }
    }
}
