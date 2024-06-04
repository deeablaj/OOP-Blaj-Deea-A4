#include "Contact.h"
#include "ContactType.h"
#include <vector>
#include "Friend.h"
#include <iostream>
#include "Colleague.h"
#include "Acquaintance.h"

using namespace std;

class AddressBook
{
	vector<Contact*> contacts;
public:
    Contact* CautaContact(const char* name) ///cauta un contact dupa nume
    {
        for (auto contact : contacts)
            if (contact->GetName() == name) return contact;
        return nullptr;

    }
    vector<Friend*> ListFriends() ///returneaza contactele de tip friend
    {
        vector<Friend*>friends;
        for (auto contact : contacts) ///parcurgem toate contactele
            if (contact->getType() == ContactType::FRIEND)
                friends.push_back(static_cast<Friend*>(contact)); //il convertim de la Contact la Friend
        return friends;
    }

    void StergeContact(const char* nume) ///sterge un contact cautand dupa nume
    {
       for (auto i = contacts.begin(); i != contacts.end(); i++) ///parcurgem toate contactele
           if (nume == (*i)->GetName()) ///daca l-am gasit
            {
                contacts.erase(i); //il eliminam
                break;
            }
    }
    void AdaugaContact(Contact* contact) ///adauga un anumit contact
    {
        contacts.push_back(contact); ///adaugam contactul
    }

};

