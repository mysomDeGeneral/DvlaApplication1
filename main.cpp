#include <iostream>
#include <string>
#include <ctime>
//#include <cstdlib>
using namespace std;




class DvlaRegistration
{
    protected:
        string expiring_date;
        string renewal_date;
        string Number;
        int Year;

        bool new_registration;

    public:
        virtual void register_new()
        {
            cout<<"new";
        }
        virtual void renew()
        {
            cout<<"renew";
        }

        void generate_number()
        {
            char alpha[26] = { 'A','B','C','D','E','F','G',
                                'H','I','J','K','L','M','N',
                                'O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z'};

            char num[10] = {'0','1','2','3','4','5','6','7','8','9'};

            string one = "";
            string two = "";
            string three = "";
            string year =to_string(Year);

            for(int i = 0; i<3; i++)
                one = one + alpha[rand()%3];

            for(int i = 0; i<4; i++)
                two = two + num[rand()%4];

            for(int i = 0; i<5; i++)
                three = three + num[rand()%5];

            string mix =  two + year;



            Number = one + '-' + mix +'-'+ three;

        }

        string get_number(){
            return Number;
        }

         void generate_date()
        {
            int year, month, day;

            time_t now = time(0);
            tm *ltm = localtime(&now);
            year = 1900 + ltm->tm_year;
            month = 1+ ltm->tm_mon;
            day = ltm->tm_mday;
            int xyear = year + 5;






            renewal_date = to_string(year) + '-' + to_string(month) + '-' + to_string(day);
            expiring_date = to_string(xyear) + '-' + to_string(month) + '-' + to_string(day);

        }



};

class VehicleRegistration :public DvlaRegistration
{
    private:
        string Brand;
        string Model;


    public:
        VehicleRegistration(string brand, string model): Brand(brand), Model(model)
        {}
        void setBrand(string brand)
        {
            Brand = brand;
        }
        string getBrand()
        {
            return Brand;
        }
        void renew()
        {
            //generate new date
        }
        void generate_number()
        {
            char alpha[26] = { 'A','B','C','D','E','F','G',
                                'H','I','J','K','L','M','N',
                                'O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z'};

            char num[10] = {'0','1','2','3','4','5','6','7','8','9'};

            time_t now = time(0);
            tm *ltm = localtime(&now);
            Year = 1900 + ltm->tm_year;

            string one = "";
            string two = "";
            string year = to_string(Year);


            string three = year.substr(2,3);


            for(int i = 0; i<2; i++)
                one = one + alpha[rand()%3];

            for(int i = 0; i<4; i++)
                two = two + num[rand()%8];


            Number = one + '-' + two +'-'+ three;
        }




};

class LicenseRegistration : public DvlaRegistration
{
    private:
        string Name;
        string Gender;
        int Age;




    public:
        LicenseRegistration(string name, string gender, int age):Name(name), Gender(gender), Age(age)
            {}


        void setName(string name)
        {
            Name = name;
        }
        void getName()
        {
            cout<< Name;
        }
        void register_new(string number)
        {
            Number = number;
        }

        void generate_date()
        {
            int year, month, day;

            time_t now = time(0);
            tm *ltm = localtime(&now);
            year = 1900 + ltm->tm_year;
            month = 1+ ltm->tm_mon;
            day = ltm->tm_mday;
            int xyear = year + 5;

            Year = year;




            renewal_date = to_string(year) + '-' + to_string(month) + '-' + to_string(day);
            expiring_date = to_string(xyear) + '-' + to_string(month) + '-' + to_string(day);

        }






















};






int main()
{
    //LicenseRegistration l1 = LicenseRegistration("Mike","male",21);
    //VehicleRegistration l2 = VehicleRegistration("toyota","2020");
    //l2.generate_date();
    //l2.generate_number();
    //cout<<"l2"<<l2.get_number()<<endl;
    //l1.generate_date();
    //l1.generate_number();
    //l1.get_date();
    //cout<<"l1"<<l1.get_number();



    return 0;
}
