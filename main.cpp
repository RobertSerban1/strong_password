#include <iostream>
using namespace std;
int n, change;
string s;
bool low, high, digit;

//explicatie variabile:
//s - sriul nostru de tipul "string";
//n - lungimea sirului, change - numarul de modificari, ambele de tipul int;
//low, high, digit - trei variabile booleane pentru a verifica dacă stringul contine cel putin o litera mica, o litera mare si o cifra;
int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(islower(s[i])) low = true;//daca sirul contine cel putin o litera mica, valoarea booleana "low" se seteaza la "true"
        else if(isupper(s[i])) high = true;//daca sirul contine cel putin o litera mare, valoarea booleana "high" se seteaza la "true"
        else if(isdigit(s[i])) digit = true;//daca sirul contine cel putin o cifra, valoarea booleana "digit" se seteaza la "true"
        if(i<n-2 && s[i]==s[i+1] && s[i]==s[i+2]){
            change++;
            i += 2;
            //verificam daca există trei caractere consecutive identice;
            //daca da, incrementăm "change" cu 1 si trecem peste următoarele două caractere (deoarece acestea sunt deja numarate ca fiind caractere identice);
        }
    }
    if(!low) change++;
    if(!high) change++;
    if(!digit) change++;
    //Verificam dacă stringul conține cel putin o litera mica, o litera mare și o cifra;
    //Daca nu, incrementam "change" cu 1 pentru fiecare tip lipsa.
    if(n > 20) change++;// verificam daca stringul contine mai mult de 20 caractere, caz in incrementam variabila "change";
    if(n + change < 6) change += 6 - n - change;
    //Verificam dacă lungimea stringului plus numarul de modificari necesare este mai mică decât 6.
    //Dacă da, adaugam diferenta la "change".

    if(change == 0) cout << 0 << "\0";
    else cout << change << "\0";
    //Dacă "change" este 0, stringul este deja puternic, deci returnam 0.
    //In caz contrar, returnam "change".

    return 0;
}
