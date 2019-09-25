/**
 * @file main.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Main
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <openssl/md5.h>
#include <openssl/hmac.h>
#include <boost/iostreams/device/mapped_file.hpp>
#include <iomanip>
#include <sstream>

const std::string md5_from_file(const std::string& path) {
  unsigned char result[MD5_DIGEST_LENGTH];
  boost::iostreams::mapped_file_source src(path);
  char key[] = "012345678";
  MD5((unsigned char*)src.data(), src.size(), result);
  //HMAC(EVP_md5(),key,strlen(key),(unsigned char*)src.data(), src.size(),result,NULL);

  std::ostringstream sout;
  sout << std::hex << std::setfill('0');
  for (auto c : result) sout << std::setw(2) << (int)c;

  return sout.str();
}

#include <iostream>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cerr<<"Must specify the file\n";
        exit(-1);
    }
    std::cout<<md5_from_file(argv[1])<<"  "<<argv[1]<<std::endl;
    return 0;
}
