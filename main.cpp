#include<iostream>
#include<string>
#include<ctime>
using namespace std;

string alfabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alf    ="abcdefghijklmnopqrstuvwxyz";

int pozycjaAlfabet(char znak){

    for(int i=0;i<alfabet.size();i++){

        if (alfabet[i]==znak||alf[i]==znak) {

            return i;

        }

    }

    return -1;

}

void szyfruj(string tekst,string klucz){

    string wynik;

    for(int i=0;i<tekst.size();i++){

        int pozycjaLiteryKlucza = pozycjaAlfabet( klucz[i % klucz.size()] );

        int pozycjaLiteryTekstu = pozycjaAlfabet( tekst[i] );

        wynik+=alfabet[ (pozycjaLiteryTekstu+pozycjaLiteryKlucza) % alfabet.size()];

    }

    cout<<"Wynik szyfrowania: \n"<<wynik<<endl;

}



int main(){
    double roznica;
    cout.setf(ios::fixed); //notacja zwykla, czyli nie wywali wyniku typu 1.175000e+003
    cout.precision(5); //liczba miejsc po przecinku, dokladnosc naszego wyniku
    clock_t start, koniec; //inicjacja zmiennych zegarowych
    start=clock(); //zapisanie czasu startu mierzenia

    string klucz,tekst;

    cout<<"Wprowadz tekst do zaszyfrowania:"<<endl;
    cin>>tekst;

    cout<<"Wprowadz slowo kluczowe:"<<endl;
    cin>>klucz;

    szyfruj(tekst,klucz);

    koniec=clock();//zapisanie konca mierzenia
    roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
    cout<<"Czas wykonania: "<<roznica<<endl;

    return 0;
}