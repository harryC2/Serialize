#include <iostream>
#include "DataStream.h"
#include <string>
#include "Serializable.h"
#include<map>
#include<vector>

using namespace ch_utility::serialize;


class Test : public Serializable
{
private:
    std::string  m_name;
    int m_age{0};
   
public:
    Test(){};
    Test(const std::string& name,int age):m_name(name),m_age(age){}

    ~Test(){};
    SERIALIZE(m_name,m_age)
};



void testWrite()
{
    DataStream ds;
    int n = 32;
    char a = 'a';
    std::string strTem = "hello world";
    ds << n << a << strTem;
     std::string strTem1;
    ds.writeFile(strTem1);
    ds.show();
}
void testRead()
{
    DataStream ds;
    std::string strTem1;
    ds.readData(strTem1);
    int n = 0;
    char a = 'c';
    std::string strTem;
    ds >> n >> a >> strTem;
    ds.show();
}
void testStlContain()
{
    std::vector<int> v{1,2,3};
    std::map<std::string,std::string> m;
    m["name"] = "chenHao";
    m["phone"] = "112111111";
    m["gender"] = "--";

    DataStream ds;
    ds << v<<m;
    std::string strTem;
    ds.writeFile(strTem);
    DataStream dsRead;
    dsRead.readData(strTem);
    std::vector<int> vcRead;
    std::map<std::string,std::string> mapRead;
    dsRead>>vcRead>>mapRead;
    for(const auto& item : vcRead)
    {
         std::cout<< item<<"--";
    }
        for(const auto& item : mapRead)
    {
         std::cout<< item.first<<item.second <<"--";
    }
}

void testClassSerializable()
{
    Test  test("chenhao",15);
    DataStream ds;
    ds<<test;
    
    std::string strTem;
    ds.writeFile(strTem);

    DataStream dsRead;
    dsRead.readData(strTem);
    Test testRead;
    dsRead>>testRead;
}




int main()
{
    testClassSerializable();
  //  testStlContain();
   // testWrite();
    //testRead();
    return 0;
}