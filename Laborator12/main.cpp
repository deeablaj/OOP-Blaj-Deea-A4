#include "Contact.h"
#include "ContactType.h"
#include "Friend.h"
#include "Colleague.h"
#include "Acquaintance.h"
#include "AddressBook.h"
#include <iostream>
using namespace std;

int main()
{
    AddressBook carte_date;
    Friend* prieten = new Friend("Delia","0745285297", "28.12.2004", "str.Voievozilor nr.56 bloc 12 scara B ap.5");
    Acquaintance* cunostinta = new Acquaintance("Matei", "15.05.1997");
    Colleague* coleg = new Colleague("Andreea", "0297463298", "Apple Inc.", "str.Trandafirilor nr.36 bloc 205 scara A ap.25");
    carte_date.AdaugaContact(prieten);
    cout << "Am adaugat contactul cu numele: " << prieten->GetName() << '\n';
    carte_date.AdaugaContact(cunostinta);
    cout << "Am adaugat contactul cu numele: " << cunostinta->GetName() << '\n';
    carte_date.AdaugaContact(coleg);
    cout << "Am adaugat contactul cu numele: " << coleg->GetName() << '\n';
    Contact* contact = carte_date.CautaContact("Delia");
    if (contact)
    {
        cout << "Am gasit contactul cu numele : " << contact->GetName() << '\n';
    }
    else
    {
        cout <<"Contactul cu numele "<<contact->GetName() << " nu a fost gasit." << '\n';
    }
    vector<Friend*> friends = carte_date.ListFriends();
    for (auto f : friends)
    {
        cout << "Prieten:" << f->GetName()<<'\n';
    }
    carte_date.StergeContact("Matei");
    ///cout << "Am sters contactul" << '\n';
    contact = carte_date.CautaContact("Matei");
    ///cout << "Am cautat contact" << '\n';
    if (contact)
    {
        cout << "Am gasit contactul cu numele : " << contact->GetName() << '\n';
    }
    else
    {
        cout << "Contactul nu a fost gasit." << '\n';
    }
}


