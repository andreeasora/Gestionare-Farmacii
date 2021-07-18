#include <iostream>
#include <stdlib.h> ///permite executia functiei system(...)
#include <vector> ///permite folosirea vectorilor din STL
using namespace std;
class Farmacie
{
    protected: ///date membre protected pentru ca avem mostenire
        string nume;
        int numar;
        static int n; ///variabila statica pentru a numara cate obiecte avem declarate
    public:
        Farmacie();
        Farmacie(string, int);
        Farmacie(const Farmacie&);
        virtual ~Farmacie(); ///destructor virtual-late binding
        int get_numar()const; ///functie constanta
        virtual void citire(istream&); ///citire virtuala-late binding
        virtual void afisare(ostream&); ///afisare virtuala-late binding
        friend istream& operator>>(istream&, Farmacie&);
        friend ostream& operator<<(ostream&, Farmacie&);
        Farmacie& operator=(const Farmacie &);
        static void NumarObiecte() ///metoda statica pentru afisarea numarului de obiecte
        {
           cout << "Numar obiecte: " << n;
        }
};

int Farmacie :: n; ///declaram variabila statica

Farmacie::Farmacie()
{
    nume = "";
    numar = 0;
    n++;
}

Farmacie::Farmacie(string Nume, int Numar)
{
    nume = Nume;
    numar = Numar;
}

Farmacie::Farmacie(const Farmacie &f)
{
    nume = f.nume;
    numar = f.numar;
    n = f.n;
}

Farmacie::~Farmacie()
{
    nume = "";
    numar = 0;
    n--;
}

int Farmacie::get_numar()const ///functie constanta
{
    return numar;
}

void Farmacie::citire(istream &in)
{
    cout << "\n";
    cout << "Introduceti numarul de angajati (pentru farmaciile FIZICE)/numarul de vizitatori (pentru farmaciile ONLINE): ";
    int z;
    in >> z;
    numar = z;
    string x;
    in.get();
    cout << "Introduceti numele farmaciei (pentru farmaciile FIZICE)/adresa web a farmaciei (pentru farmaciile ONLINE): ";
    getline(in, x);
    nume = x;
}

istream& operator>>(istream &in, Farmacie &f)
{
    f.citire(in);
    return in;
}

void Farmacie::afisare(ostream &out)
{
    out << "Numele farmaciei/adresa web a farmaciei este: " << nume << "\n";
    out << "Numarul de angajati/numarul de vizitatori este: " << numar << "\n";
}

ostream& operator<<(ostream &out, Farmacie &f)
{
    f.afisare(out);
    return out;
}

Farmacie& Farmacie::operator=(const Farmacie &f)
{
    if (this != &f)
    {
       nume = f.nume;
       numar = f.numar;
    }
    return *this;
}

class Farmacie_Fizica:public Farmacie
{
    private: ///date membre private pentru ca nu mai derivam din clasa Farmacie_Fizica
        int profit_luna[12];
    public:
        Farmacie_Fizica();
        Farmacie_Fizica(string, int, int*);
        Farmacie_Fizica(const Farmacie_Fizica&, const Farmacie&);
        ~Farmacie_Fizica();
        void citire(istream &);
        void afisare(ostream &);
        Farmacie_Fizica& operator=(const Farmacie_Fizica&);
};

Farmacie_Fizica::Farmacie_Fizica():Farmacie() ///apelam constructorul din baza
{
    for (int i = 0; i < 12; i++)
        profit_luna[i] = 0;
}

Farmacie_Fizica::Farmacie_Fizica(string Nume, int Nr, int v[]):Farmacie(Nume, Nr) ///apelam constructorul din baza
{
    for (int i = 0; i < 12; i++)
        profit_luna[i] = v[i];
}

Farmacie_Fizica::Farmacie_Fizica(const Farmacie_Fizica &f, const Farmacie &p):Farmacie(p) ///apelam constructorul de copiere din baza
{
    for (int i = 0; i < 12; i++)
        profit_luna[i] = f.profit_luna[i];
}

Farmacie_Fizica::~Farmacie_Fizica()
{
    for (int i = 0; i < 12; i++)
        profit_luna[i] = 0;
}

void Farmacie_Fizica::citire(istream &in)
{
    Farmacie::citire(in); ///apelam citirea din baza
    cout << "Introduceti profitul pentru fiecare luna: \n";
    for (int i = 0; i < 12; i++)
    {
        if (i == 0) cout << "Ianuarie: ";
         else if (i == 1) cout << "Februarie: ";
               else if (i == 2) cout << "Martie: ";
                    else if (i == 3) cout << "Aprilie: ";
                          else if (i == 4) cout << "Mai: ";
                               else if (i == 5) cout << "Iunie: ";
                                     else if (i == 6) cout << "Iulie: ";
                                          else if (i == 7) cout << "August: ";
                                                else if (i == 8) cout << "Septembrie: ";
                                                     else if (i == 9) cout << "Octombrie: ";
                                                           else if (i == 10) cout << "Noiembrie: ";
                                                                else cout << "Decembrie: ";
        in >> profit_luna[i];
    }
}

void Farmacie_Fizica::afisare(ostream &out)
{
    out << "Numele farmaciei este: " << nume << "\n";
    out << "Numarul de angajati este: " << numar << "\n";
    out << "Profiturile pe fiecare luna sunt: \n";
    for (int i = 0; i < 12; i++)
    {
        if (i == 0) out << "Ianuarie: ";
         else if (i == 1) out << "Februarie: ";
               else if (i == 2) out << "Martie: ";
                    else if (i == 3) out << "Aprilie: ";
                          else if (i == 4) out << "Mai: ";
                               else if (i == 5) out << "Iunie: ";
                                     else if (i == 6) out << "Iulie: ";
                                          else if (i == 7) out << "August: ";
                                                else if (i == 8) out << "Septembrie: ";
                                                     else if (i == 9) out << "Octombrie: ";
                                                           else if (i == 10) out << "Noiembrie: ";
                                                                else out << "Decembrie: ";
        out << profit_luna[i];
        out << "\n";
    }

}

Farmacie_Fizica& Farmacie_Fizica::operator=(const Farmacie_Fizica &f)
{
    if (this != &f)
    {
        Farmacie::operator=(f);
        for (int i = 0; i < 12; i++)
           profit_luna[i] = f.profit_luna[i];
    }
    return *this;
}

class Farmacie_Online:public Farmacie
{
    private: ///date membre private pentru ca nu mai derivam din clasa Farmacie_Online
        double discount;
    public:
        Farmacie_Online();
        Farmacie_Online(string, int, double);
        Farmacie_Online(const Farmacie_Online&, const Farmacie&);
        ~Farmacie_Online();
        void citire(istream &);
        void afisare(ostream &);
        Farmacie_Online& operator=(const Farmacie_Online&);

};

Farmacie_Online::Farmacie_Online():Farmacie() ///apelam constructorul din baza
{
    discount = 0.0;
}

Farmacie_Online::Farmacie_Online(string Nume, int Nr, double Discount):Farmacie(Nume, Nr) ///apelam constructorul din baza
{
    discount = Discount;
}

Farmacie_Online::Farmacie_Online(const Farmacie_Online &f, const Farmacie &p):Farmacie(p) ///apelam constructorul de copiere din baza
{
    discount = f.discount;
}

Farmacie_Online::~Farmacie_Online()
{
    discount = 0.0;
}

void Farmacie_Online::citire(istream &in)
{
    Farmacie::citire(in); ///apelam citirea din baza
    cout << "Introduceti discountul utilizat: ";
    in >> discount;
}

void Farmacie_Online::afisare(ostream &out)
{
    out << "Adresa web a farmaciei este: " << nume << "\n";
    out << "Numarul de vizitatori este: " << numar << "\n";
    out << "Discountul utilizat este: " << discount << "\n";
}

Farmacie_Online& Farmacie_Online::operator=(const Farmacie_Online &f)
{
    if (this != &f)
    {
        Farmacie::operator=(f);
        discount = f.discount;
    }
    return *this;
}

template <class Tip> class GestionareFarmacii
{
    private:
       static int index; ///index farmacie
       static const int id = 1; ///id lant -- farmacii fizice - "static const" deoarece este mai eficient din punct de vedere al memoriei fata de "const"
       vector <Tip*> v; ///structura de obiecte
    public:
       GestionareFarmacii()
       {
           index = 0;
       }
       ~GestionareFarmacii()
       {
           index = 0;
           v.clear();
       }
       void operator+=(const Tip &f)
       {
           index++;
           Tip *F = new Tip(f);
           v.push_back(F);
       }
       void afisare_informatii()
       {
           cout << "Id lant farmacii fizice: ";
           cout << id << "\n";
           cout << "Numarul de farmacii din lant: " << index << "\n";
           int i;
           if (index != 0)
           {
               cout << "Farmaciile sunt: " << "\n";
               for(i = 0; i < (int)v.size(); i++)
                     {
                         cout << "Farmacia " << i+1 << ": " << "\n" << *(v[i]);
                         cout << "\n";
                     }
           }
       }
};

template <class Tip> int GestionareFarmacii <Tip> :: index; ///declaram variabila statica

template <> class GestionareFarmacii <Farmacie_Online> ///specializare farmacie online
{
    private:
       static int index; ///index farmacie
       static const int id = 2; ///id lant -- farmacii online - "static const" deoarece este mai eficient din punct de vedere al memoriei fata de "const"
       vector <Farmacie_Online*> v; ///structura de obiecte
    public:
        GestionareFarmacii()
        {
           index = 0;
        }
       ~GestionareFarmacii()
        {
           index = 0;
           v.clear();
        }
        void operator+=(const Farmacie_Online &f)
        {
           index++;
           Farmacie_Online *F = new Farmacie_Online(f);
           v.push_back(F);
        }
        void afisare_nr_vizitatori()
        {
           Farmacie_Online f;
           int i, viz = 0;
           cout << "\n";
           cout << "Numarul total de vizitatori din farmaciile online: ";
           for(i = 0; i < (int)v.size(); i++)
           {
             f = *(v[i]);
             viz += f.get_numar();
           }
           cout << viz;
        }
};

template <> int GestionareFarmacii <Farmacie_Online> :: index; ///declaram variabila statica

void tip(Farmacie *&p, int i)
{
    string s;
    cout << "\n";
    cout << "Introduceti tipul farmaciei (fizica/online) " << ": ";
    cin >> s;
    try ///alegem tipul farmaciei pe care dorim sa o citim
    {
        if(s == "fizica")
        {
            p = new Farmacie_Fizica;
            cin >> *p;
        }
        else
            if(s == "online")
            {
                p = new Farmacie_Online;
                cin >> *p;
            }
                else
                    throw 10;
    }
    catch(int j)
    {
        cout << "Nu ati introdus o farmacie valida! Incercati fizica sau online!\n ";
        exit(EXIT_FAILURE);
    }
}

void menu_output()
{
    cout << "Nume: Sora Andreea-Ioana/ Grupa: 134/ Proiect 3 POO - Tema 6 - Gestionare farmacii \n";
    cout << "-----------------------MENIU----------------------";
    cout << "\n";
    cout << "1. Citire n farmacii"; cout << "\n";
    cout << "2. Afisare n farmacii"; cout << "\n";
    cout << "3. Afisare farmacie cu indicele i"; cout << "\n";
    cout << "4. Gestionare farmacii -- Template (farmacii fizice)"; cout << "\n";
    cout << "5. Gestionare farmacii -- Template (farmacii online) -- SPECIALIZARE"; cout << "\n";
    cout << "6. Afisati numarul de farmacii"; cout << "\n";
    cout << "0. Iesire."; cout << "\n";
}

void menu()
{
    int option;///optiunea aleasa din meniu
    option = 0;
    int n,i,ok = 0;
    menu_output();
    cout << "\nIntroduceti n (numarul de farmacii): ";
    cin >> n;
    try
    {
        if (n <= 0)
           throw 1;
    }
    catch(int i)
    {
        cout << "Numarul nu poate fi mai mic sau egal cu 0!";
        exit(EXIT_FAILURE);
    }
    Farmacie **f; ///upcast
    do
    {
        if (ok == 1)
            menu_output();
        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;
        if (ok == 0 && option != 1)
        {
            cout << "Invalid, pentru inceput trebuie sa cititi cele n farmacii!\n";
            option = 1;
        }
        if (option == 1) ///citire farmacii
        {
            f = new Farmacie*[n]; ///aloc memorie pentru n obiecte de tip Farmacie, apoi pentru fiecare obiect il etichetez cu tipul corespunzator (fizica/online)
            for (i = 0; i < n; i++)
                 tip(f[i], i);
        }
        if (option == 2) ///afisare farmacii
        {
            cout << "\n";
            for (i = 0; i < n; i++)
            {
                cout << "Farmacie " << i+1 << ":" << "\n";
                cout << *f[i] << "\n";
            }
        }
        if (option == 3) ///afisare farmacie indice i
        {
           cout << "\n";
           cout << "Introduceti i: ";
           cin >> i;
           try
           {
              if (i >= n || i < 0)
                throw 1;
           }
           catch(int j)
           {
             cout << "Invalid, indicele trebuie sa fie mai mic decat " << n << " si mai mare sau egal decat 0!\n";
             exit(EXIT_FAILURE);
           }
           cout << "\n";
           cout << *f[i] << "\n";
        }
        if (option == 4) ///downcast
        {
            GestionareFarmacii <Farmacie_Fizica> x;
            for (i = 0; i < n; i++)
            {
               Farmacie_Fizica *p1 = dynamic_cast <Farmacie_Fizica*> (f[i]); ///incerc cast catre farmacie_fizica
               if (p1) ///daca e diferit de null atunci adaug in gestiunea mea de farmacii fizice
                    x += *p1;
            }
            cout << "\n";
            x.afisare_informatii();
        }
        if (option == 5) ///downcast
        {
            GestionareFarmacii <Farmacie_Online> x;
            for (i = 0; i < n; i++)
            {
               Farmacie_Online *p2 = dynamic_cast <Farmacie_Online*> (f[i]); ///incerc cast catre farmacie_online
               if (p2) ///daca e diferit de null atunci adaug in gestiunea mea de farmacii online
                  x += *p2;
            }
            x.afisare_nr_vizitatori();
            cout << "\n";
        }
        if (option == 6)
        {
            cout << "\n";
            Farmacie::NumarObiecte(); ///afisam numarul de obiecte
            cout << "\n";
        }
        if (option == 0)
        {
            cout<<"\nIESIRE!\n";
        }
        if (option < 0 || option > 6)
        {
            cout<<"\nSelectie invalida!!!\n";
        }
        ok=1;
        cout << "\n";
        system("pause");
        system("cls");
    }
    while(option != 0);
}
int main()
{
    menu();
    cout << "O zi buna!";
    return 0;
}
