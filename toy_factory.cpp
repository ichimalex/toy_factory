#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
class Jucarie
{
    protected:
    std::string tematica,nume;
    char tip;
    public:
    virtual void afisare()=0;
    Jucarie(char tip,std::string tematica, std::string nume):tematica(tematica),nume(nume){}
    std::string get_tematica()
    {
        return tematica;
    }
    virtual void afis()=0;
    virtual float dimensiune(){return 0;}
};
class Action:public Jucarie
{
    private:
    int inaltime,latime,lungime;
    public:
    Action(char tip,std::string tematica, std::string nume,int inaltime,int latime,int lungime):
    Jucarie(tip,tematica,nume),inaltime(inaltime),latime(latime),lungime(lungime){}
    void afisare()
    {
        std::cout<<"Action_figure "<<tematica<<" "<<nume<<" "<<inaltime<<" "<<latime<<" "<<lungime<<std::endl;
    }
    
    float dimensiune()
    {
        float mini=999;
        if(mini>inaltime)mini=inaltime;
        if(mini>latime)mini=latime;
        if(mini>lungime)mini=lungime;
        return mini;
    }
    void afis()
    {
        std::cout<<"Action_figure "<<nume<<" "<<floor(10/dimensiune())<<std::endl;
    }
};
class Puzzle:public Jucarie
{
    private:
    int numar,latime,lungime;
    public:
    Puzzle(char tip,std::string tematica,std::string nume,int numar,int latime,int lungime):
    Jucarie(tip,tematica,nume),numar(numar),latime(latime),lungime(lungime){}
    void afisare()
    {
        std::cout<<"Puzzle "<<tematica<<" "<<nume<<" "<<numar<<" "<<latime<<" "<<lungime<<std::endl;
    }
    float dimensiune()
    {
        float dim1,dim2;
        dim1=latime/sqrt(numar);
        dim2=lungime/sqrt(numar);
        if(dim1<dim2)return dim1;
        else return dim2;
    }
    void afis()
    {
        std::cout<<"Puzzle "<<nume<<" "<<floor(10/dimensiune())<<std::endl;
    }
};

bool metoda(Jucarie *j1, Jucarie *j2)
{
    return(floor(10/ j1->dimensiune())<floor(10/ j2->dimensiune()));
}

class Gestionare
{
    private:
    std::vector<Jucarie*> vec;
    public:
    void vec_add(Jucarie *j)
    {
        vec.push_back(j);
    }
    void test1()
    {
        for(int i=0;i<vec.size();i++)
        {
            vec[i]->afisare();
        }
    }
    void test2(std::string x)
    {
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]->get_tematica()==x)
            {
                vec[i]->afisare();
            }
        }
    }
    
    void test3()
    {
        for(int i=0;i<vec.size();i++)
        {
            vec[i]->afis();
        }
    }
    void test4()
    {
        std::sort(vec.begin(),vec.end(),metoda);
    }
};
int main()
{
    Gestionare obiect;
    int n,test;
    std::string nume,tematica;
    int lungime,latime,inaltime,numar;
    char tip;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::cin>>tip;
        std::cin.ignore();
        std::getline(std::cin, tematica);
        std::getline(std::cin, nume);
        if(tip=='a')
        {
            std::cin>>inaltime>>latime>>lungime;
            obiect.vec_add(new Action(tip,tematica,nume,inaltime,latime,lungime));
            
        }
        else {
            std::cin>>numar>>latime>>lungime;
            obiect.vec_add(new Puzzle(tip,tematica,nume,numar,latime,lungime));
        }
    }
    std::cin>>test;
    switch (test){
        case 1:
        {
           obiect.test1();
          break;
        }
        case 2:
        {
            std::cin>>tematica;
            obiect.test2(tematica);
            break;
        }
        case 3:
        {
            obiect.test3();
            break;
        }
        case 4:
        {
            obiect.test4();
            obiect.test1();
            break;
        }
        
    }
    return 0;
    
}
