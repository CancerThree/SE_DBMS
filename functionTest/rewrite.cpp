#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream x("tmp.txt",ios::out|ios::binary|ios::app) ;
    ifstream xx("tmp.txt") ;
    char ori[10] = "this is" ;
    char rewrite[4] = {'m','e','m','e'} ;
    x.write(ori,sizeof(ori)) ;
    char buffer[10] ;
    xx.read(buffer,sizeof(buffer)) ;
    cout << buffer ;
    //���ļ�ָ���ƶ�����Ҫ�޸ĵĵط�����д����ֵ�����ܸ��ǵ�ԭ��������
    x.seekg(0,x.beg) ;
    x.write(rewrite,sizeof(rewrite)) ;
    x.flush() ;//�ǵü�ʱflush����������д����̣�����ֻ���ڹرպ�������ݲſ��ܸ��ģ��ᵼ�³���
    xx.read(buffer,sizeof(buffer)) ;
    cout << buffer ;
    x.close() ;
    xx.close() ;
    return 0;
}
