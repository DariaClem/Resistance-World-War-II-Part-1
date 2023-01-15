#include <bits/stdc++.h>

using namespace std;

/* Armament class records data on the number of pistols, machine guns and rifles in the equipment of the resistance. May
 * check if their number is sufficient for all people. */
class Armament {
public:
    Armament();

    Armament(int, int, int);

    Armament(const Armament &);

    void set_nrpistoale(int);

    void set_nrmitraliere(int);

    void set_nrpusti(int);

    int get_nrpistoale();

    int get_nrmitraliere();

    int get_nrpusti();

    friend istream &operator>>(istream &stream, Armament &armament);

    friend ostream &operator<<(ostream &stream, Armament &armament);

    Armament operator+=(int arm2);

    Armament operator-=(int arm2);

    Armament operator+(Armament arm2);

    Armament operator-(Armament arm2);

    friend class Munitie;

    bool verificare_cantitate(int);

private:
    int nr_pistoale, nr_mitraliere, nr_pusti;
};

Armament::Armament() {}

Armament::Armament(int pistoale, int mitraliere, int pusti) {
    this->nr_pistoale = pistoale;
    this->nr_mitraliere = mitraliere;
    this->nr_pusti = pusti;
}

Armament::Armament(const Armament &arme) {
    this->nr_pistoale = arme.nr_pistoale;
    this->nr_pusti = arme.nr_pusti;
    this->nr_mitraliere = arme.nr_mitraliere;
}

void Armament::set_nrpistoale(int pistoale) {
    this->nr_pistoale = pistoale;
}

void Armament::set_nrpusti(int pusti) {
    this->nr_pusti = pusti;
}

void Armament::set_nrmitraliere(int mitraliere) {
    this->nr_mitraliere = mitraliere;
}

int Armament::get_nrpistoale() {
    return this->nr_pistoale;
}

int Armament::get_nrpusti() {
    return this->nr_pusti;
}

int Armament::get_nrmitraliere() {
    return this->nr_mitraliere;
}

bool Armament::verificare_cantitate(int nr_oameni) {
    if (nr_mitraliere + nr_pusti + nr_pistoale >= nr_oameni)
        return true;
    return false;
}

Armament Armament::operator+=(int arm2) {
    this->nr_pusti = nr_pusti + arm2;
    this->nr_mitraliere = nr_mitraliere + arm2;
    this->nr_pistoale = nr_pistoale + arm2;
    return *this;
}

Armament Armament::operator+(Armament arm2) {
    this->nr_pusti += arm2.nr_pusti;
    this->nr_pistoale += arm2.nr_pistoale;
    this->nr_mitraliere += arm2.nr_mitraliere;
    return *this;
}

Armament Armament::operator-=(int arm2) {
    this->nr_pusti -= arm2;
    this->nr_pistoale -= arm2;
    this->nr_mitraliere -= arm2;
    return *this;
}

Armament Armament::operator-(Armament arm2) {
    this->nr_pusti -= arm2.nr_pusti;
    this->nr_pistoale -= arm2.nr_pistoale;
    this->nr_mitraliere -= arm2.nr_mitraliere;
    return *this;
}

istream &operator>>(istream &stream, Armament &armament) {
    stream >> armament.nr_pistoale >> armament.nr_pusti >> armament.nr_mitraliere;
    return stream;
}

ostream &operator<<(ostream &stream, Armament &armament) {
    stream << armament.nr_pistoale << " " << armament.nr_mitraliere << " " << armament.nr_pusti << "\n";
    return stream;
}

/* The Ammunition Class records the number of bullets for each individual weapon. It can be checked if their number
 * is enough to charge a charger. */
class Munitie {
public:
    Munitie();

    Munitie(int, int, int);

    Munitie(const Munitie &);

    void set_gloantepistoale(int);

    void set_gloantepusti(int);

    void set_gloantemitraliere(int);

    int get_gloantepistoale();

    int get_gloantemitraliere();

    int get_gloantepusti();

    friend istream &operator>>(istream &stream, Munitie &);

    friend ostream &operator<<(ostream &stream, Munitie &);

    Munitie operator+=(int mun2);

    Munitie operator-=(int mun2);

    Munitie operator+(Munitie mun2);

    Munitie operator-(Munitie mun2);

    bool verificare_munitie(Armament);

private:
    int gloante_pistoale, gloante_mitraliere, gloante_pusti;
};

Munitie::Munitie() {}

Munitie::Munitie(int gl_pistoale, int gl_pusti, int gl_mitraliere) {
    this->gloante_pistoale = gl_pistoale;
    this->gloante_mitraliere = gl_mitraliere;
    this->gloante_pusti = gl_pusti;
}

Munitie::Munitie(const Munitie &munitie) {
    this->gloante_pistoale = munitie.gloante_pistoale;
    this->gloante_pusti = munitie.gloante_pusti;
    this->gloante_mitraliere = munitie.gloante_mitraliere;
}

void Munitie::set_gloantepistoale(int cant) {
    gloante_pistoale = cant;
}

void Munitie::set_gloantepusti(int cant) {
    gloante_pusti = cant;
}

void Munitie::set_gloantemitraliere(int cant) {
    gloante_mitraliere = cant;
}

int Munitie::get_gloantepistoale() {
    return gloante_pistoale;
}

int Munitie::get_gloantemitraliere() {
    return gloante_mitraliere;
}

int Munitie::get_gloantepusti() {
    return gloante_pusti;
}

bool Munitie::verificare_munitie(Armament armament) {
    if (gloante_pistoale < 12 * armament.nr_pistoale) return false;
    if (gloante_pusti < 30 * armament.nr_pusti) return false;
    if (gloante_mitraliere < 30 * armament.nr_mitraliere) return false;
    return true;
}

Munitie Munitie::operator-=(int mun2) {
    this->gloante_pusti -= mun2;
    this->gloante_mitraliere -= mun2;
    this->gloante_pistoale -= mun2;
    return *this;
}

Munitie Munitie::operator-(Munitie mun2) {
    this->gloante_pusti -= mun2.gloante_pusti;
    this->gloante_mitraliere -= mun2.gloante_mitraliere;
    this->gloante_pistoale -= mun2.gloante_pistoale;
    return *this;
}

Munitie Munitie::operator+(Munitie mun2) {
    this->gloante_pusti += mun2.gloante_pusti;
    this->gloante_mitraliere += mun2.gloante_mitraliere;
    this->gloante_pistoale += mun2.gloante_pistoale;
    return *this;
}

Munitie Munitie::operator+=(int mun2) {
    this->gloante_pusti += mun2;
    this->gloante_mitraliere += mun2;
    this->gloante_pistoale += mun2;
    return *this;
}

istream &operator>>(istream &stream, Munitie &munitie) {
    stream >> munitie.gloante_pistoale >> munitie.gloante_mitraliere >> munitie.gloante_pusti;
    return stream;
}

ostream &operator<<(ostream &stream, Munitie &munitie) {
    stream << munitie.gloante_pistoale << " " << munitie.gloante_mitraliere << " " << munitie.gloante_pusti << "\n";
    return stream;
}

class coordonate {
public:
    coordonate();

    coordonate(int, int, int);

    coordonate(const coordonate &);

    void set_grade(int);

    void set_minute(int);

    void set_secunde(int);

    int get_grade();

    int get_minute();

    int get_secunde();

    void coord_atac(int, int, int, int);

    void determinare_coordonate(float);

    friend istream &operator>>(istream &, coordonate &);

    friend ostream &operator<<(ostream &, coordonate &);

    friend bool operator!=(coordonate, coordonate);

    friend class Decriptare;

    friend class Atacuri;

    coordonate &operator=(coordonate);

private:
    int grade, minute, secunde;
};

coordonate::coordonate() {}

coordonate::coordonate(int gr, int min, int sec) {
    this->grade = gr;
    this->minute = min;
    this->secunde = sec;
}

coordonate::coordonate(const coordonate &coord) {
    this->grade = coord.grade;
    this->minute = coord.minute;
    this->secunde = coord.secunde;
}

void coordonate::set_grade(int gr) {
    this->grade = gr;
}

void coordonate::set_minute(int min) {
    this->minute = min;
}

void coordonate::set_secunde(int sec) {
    this->secunde = sec;
}

int coordonate::get_grade() {
    return this->grade;
}

int coordonate::get_minute() {
    return this->minute;
}

int coordonate::get_secunde() {
    return this->secunde;
}

void coordonate::determinare_coordonate(float valoare) {
    this->grade = int(valoare);
    this->minute = int((valoare - this->grade) * 60);
    this->secunde = round((valoare - this->grade - this->minute / 60.0) * 3600);
}

void coordonate::coord_atac(int gr, int min, int sec, int alterare) {
    this->grade = gr * alterare;
    this->minute = min * alterare + (this->grade);
    this->secunde = sec * alterare;
}

bool operator!=(coordonate coord1, coordonate coord2) {
    if (coord1.grade == coord2.grade)
        return false;
    if (coord1.minute == coord2.minute)
        return false;
    if (coord1.secunde == coord2.secunde)
        return false;
    return true;
}

coordonate &coordonate::operator=(coordonate coord) {
    this->grade = coord.grade;
    this->minute = coord.minute;
    this->secunde = coord.secunde;
    return *this;
}

istream &operator>>(istream &stream, coordonate &coord) {
    stream >> coord.grade >> coord.minute >> coord.secunde;
    return stream;
}

ostream &operator<<(ostream &stream, coordonate &coord) {
    char grad = 248;
    stream << coord.grade << grad << coord.minute << "'" << coord.secunde << "''\n";
    return stream;
}

class Oameni {
public:
    Oameni();

    Oameni(int, string);

    Oameni(const Oameni &);

    void set_Id(int);

    void set_misiune(string);

    int get_Id();

    string get_misiune();

    friend istream &operator>>(istream &, Oameni &);

    friend ostream &operator<<(ostream &, Oameni &);

    friend class Decriptare;

    friend bool operator==(Oameni, Oameni);

    Oameni &operator=(Oameni);

private:
    int ID_om;
    string misiune;
};

Oameni::Oameni() {};

Oameni::Oameni(int nr, string mis) {
    this->ID_om = nr;
    this->misiune = mis;
}

Oameni::Oameni(const Oameni &oameni) {
    this->ID_om = oameni.ID_om;
    this->misiune = oameni.misiune;
}

void Oameni::set_Id(int id) {
    this->ID_om = id;
}

void Oameni::set_misiune(string mis) {
    this->misiune = mis;
}

int Oameni::get_Id() {
    return this->ID_om;
}

string Oameni::get_misiune() {
    return this->misiune;
}

bool operator==(Oameni om1, Oameni om2) {
    if (om1.ID_om == om2.ID_om and om1.misiune == om2.misiune)
        return true;
    return false;
}

Oameni &Oameni::operator=(Oameni om) {
    this->ID_om = om.ID_om;
    this->misiune = om.misiune;
    return *this;
}

istream &operator>>(istream &citire, Oameni &om) {
    citire >> om.ID_om >> om.misiune;
    return citire;
}

ostream &operator<<(ostream &afisare, Oameni &om) {
    afisare << om.ID_om << " " << om.misiune << "\n";
    return afisare;
}

class Decriptare {
public:
    Decriptare();

    Decriptare(string, Oameni, int, coordonate);

    Decriptare(const Decriptare &);

    void set_mesaj(string);

    void set_id(Oameni);

    void set_cheie(int);

    string get_mesaj();

    Oameni get_id();

    int get_cheie();

    coordonate get_coordonate();

    int verificare_autenticitate(Oameni, coordonate);

    void decriptare_mesaj();

    friend istream &operator>>(istream &, Decriptare &);

    friend ostream &operator<<(ostream &, Decriptare &);

    Decriptare &operator=(Decriptare);

private:
    string mesaj;
    int cheie;
    Oameni ID_mesager;
    coordonate coordonate_mesaj;
};

Decriptare::Decriptare() {}

Decriptare::Decriptare(string msj, Oameni id, int key, coordonate coord) {
    this->mesaj = msj;
    this->cheie = key;
    this->ID_mesager = id;
    this->coordonate_mesaj = coord;
}

Decriptare::Decriptare(const Decriptare &decriptare) {
    this->ID_mesager = decriptare.ID_mesager;
    this->cheie = decriptare.cheie;
    this->mesaj = decriptare.mesaj;
    this->coordonate_mesaj = decriptare.coordonate_mesaj;
}

void Decriptare::set_cheie(int key) {
    this->cheie = key;
}

void Decriptare::set_id(Oameni om) {
    this->ID_mesager = om;
}

void Decriptare::set_mesaj(string msj) {
    this->mesaj = msj;
}

string Decriptare::get_mesaj() {
    return this->mesaj;
}

int Decriptare::get_cheie() {
    return this->cheie;
}

Oameni Decriptare::get_id() {
    return this->ID_mesager;
}

coordonate Decriptare::get_coordonate() {
    return this->coordonate_mesaj;
}

int Decriptare::verificare_autenticitate(Oameni om, coordonate coord) {
    if (om.ID_om < this->cheie)
        return 0;
    if ((om.ID_om - this->cheie) % 2 == 0)
        return 0;
    if ((coord.grade + coord.minute + coord.secunde) % 2 == 0)
        return 0;
    return 1;
}

void Decriptare::decriptare_mesaj() {
    int i;
    for (i = 0; this->mesaj[i]; i += 1)
        this->mesaj[i] = this->mesaj[i] xor this->cheie;
}

Decriptare &Decriptare::operator=(Decriptare decript) {
    this->mesaj = decript.mesaj;
    this->cheie = decript.cheie;
    this->ID_mesager = decript.ID_mesager;
    this->coordonate_mesaj = decript.coordonate_mesaj;
    return *this;
}

istream &operator>>(istream &citire, Decriptare &decriptare) {
    citire.get();
    getline(citire, decriptare.mesaj);
    citire >> decriptare.ID_mesager;
    citire >> decriptare.cheie;
    citire >> decriptare.coordonate_mesaj;
    return citire;
}

ostream &operator<<(ostream &afisare, Decriptare &decriptare) {
    afisare << "ID_mesager: " << decriptare.ID_mesager;
    afisare << "Message: " << decriptare.mesaj;
    afisare << "\nKey: " << decriptare.cheie;
    afisare << "\nCoordinates: " << decriptare.coordonate_mesaj << "\n";
    return afisare;
}

class Atacuri {
public:
    Atacuri();

    Atacuri(int, int, int, int, int, coordonate);

    Atacuri(const Atacuri &);

    void set_luna(int);

    void set_zi(int);

    void set_an(int);

    void set_ora(int);

    void set_km(int);

    void set_zona(coordonate);

    int get_luna();

    int get_zi();

    int get_an();

    int get_ora();

    int get_km();

    coordonate get_zona();

    friend istream &operator>>(istream &, Atacuri &);

    friend ostream &operator<<(ostream &, Atacuri &);

    bool verificare_siguranta(int, int);

private:
    int luna, zi, an, ora, km_de_capitala;
    coordonate zona;
};

Atacuri::Atacuri() {}

Atacuri::Atacuri(int h, int d, int m, int y, int km, coordonate coord) {
    this->ora = h;
    this->zi = d;
    this->luna = m;
    this->an = y;
    this->km_de_capitala = km;
    this->zona = coord;
}

Atacuri::Atacuri(const Atacuri &atacuri) {
    this->zi = atacuri.zi;
    this->luna = atacuri.luna;
    this->an = atacuri.an;
    this->ora = atacuri.ora;
    this->km_de_capitala = atacuri.km_de_capitala;
    this->zona = atacuri.zona;
}

void Atacuri::set_ora(int h) {
    this->ora = h;
}

void Atacuri::set_zi(int d) {
    this->zi = d;
}

void Atacuri::set_luna(int m) {
    this->luna = m;
}

void Atacuri::set_an(int y) {
    this->an = y;
}

void Atacuri::set_km(int km) {
    this->km_de_capitala = km;
}

void Atacuri::set_zona(coordonate coord) {
    this->zona = coord;
}

int Atacuri::get_ora() {
    return this->ora;
}

int Atacuri::get_zi() {
    return this->zi;
}

int Atacuri::get_luna() {
    return this->luna;
}

int Atacuri::get_an() {
    return this->an;
}

int Atacuri::get_km() {
    return this->km_de_capitala;
}

coordonate Atacuri::get_zona() {
    return this->zona;
}

bool Atacuri::verificare_siguranta(int h, int km) {
    if (!(h < 8 or h > 20))
        return false;
    if (km > 100)
        return false;
    return true;
}

istream &operator>>(istream &citire, Atacuri &atacuri) {
    citire >> atacuri.ora >> atacuri.zi >> atacuri.luna >> atacuri.an >> atacuri.zona;
    return citire;
}

ostream &operator<<(ostream &afisare, Atacuri &atacuri) {
    afisare << "The attack will take place at \nTime: " << atacuri.ora << ":00\nDay: " << atacuri.zi << "\nMonth: "
            << atacuri.luna
            << "\nYear: " << atacuri.an << "\nCoordinate are: " << atacuri.zona << "The attack takes place at "
            << atacuri.km_de_capitala
            << "km from Paris.\n";
    return afisare;
}

int main() {
    int nr_oameni;
    cout << "The number of people in the Resistance:";
    cin >> nr_oameni;

    Armament arm1(10, 10, 10);
    Armament arm2(30, 50, 80);

    Munitie mun1(30, 30, 30);
    Munitie mun2(5, 7, 21);

    Atacuri atac1;
    Atacuri atac2;

    coordonate coord1(10, 20, 31);
    coordonate coord2(67, 30, 2);
    coordonate coord3(78, 29, 10);
    coordonate coord4(10, 28, 9);
    coordonate coord5(17, 10, 18);
    coordonate coord6;

    Oameni membru1(170, "gestionar_arme");
    Oameni membru2(125, "gestionar_munitie");
    Oameni membru3(782, "spion");
    Oameni membru4(28, "militar");
    Oameni membru5(73, "strateg");
    Oameni membru;

    Decriptare mesaj1("31", membru1, 1, coord1);
    Decriptare mesaj2("32", membru2, 2, coord2);
    Decriptare mesaj3("2\\26\\0\\2:77\\1", membru3, 3, coord3);
    Decriptare mesaj4("5", membru4, 4, coord4);
    Decriptare mesaj5("5Z1", membru4, 5, coord4);
    Decriptare mesaj6("oY2Y3Y0Y70", membru5, 6, coord5);
    Decriptare mesaj7("`Y2(3", membru5, 6, coord5);
    Decriptare mesaj;

    int index;
    mesaj = mesaj1;
    membru = mesaj.get_id();

    for (index = 1; index <= 7; index++) {
        if (mesaj.verificare_autenticitate(membru, mesaj.get_coordonate())) {
            mesaj.decriptare_mesaj();
            if (membru.get_misiune() == "gestionar_arme") {
                int nr;
                nr = stoi(mesaj.get_mesaj());
                arm1 += nr;
                cout << "Number of weapons: " << arm1;
            }
            if (membru.get_misiune() == "gestionar_munitie") {
                int nr;
                nr = stoi(mesaj.get_mesaj());
                mun1 += nr;
                cout << "Number of ammo: " << mun1;
            }
            if (membru.get_misiune() == "spion") {
                char valori[1001], *p;
                strcpy(valori, (mesaj.get_mesaj()).c_str());
                p = strtok(valori, "_");
                atac1.set_ora(atoi(p));
                p = strtok(NULL, "_");
                atac1.set_zi(atoi(p));
                p = strtok(NULL, "_");
                atac1.set_luna(atoi(p));
                p = strtok(NULL, "_");
                atac1.set_an(atoi(p));
                p = strtok(NULL, "_");
                atac1.set_km(atoi(p));
                atac1.set_zona(coord3);
                if (atac1.verificare_siguranta(atac1.get_ora(), atac1.get_km()))
                    cout << "The attack can take place.\n";
                else
                    cout << "The attack cannot take place.\n";
            }
            if (membru.get_misiune() == "militar") {
                char valori[1001], *p;
                strcpy(valori, (mesaj.get_mesaj()).c_str());
                p = strtok(valori, "_");
                if (atoi(p) == 1) {
                    // victory -> get weapons
                    p = strtok(NULL, "_");
                    cout << "Victory\n";
                    arm1 = arm1 + arm2;
                    mun1 = mun1 + mun2;
                    cout << arm1 << arm2;
                } else {
                    // defeat -> give up arms
                    p = strtok(NULL, "_");
                    arm1 -= atoi(p);
                    mun1 -= atoi(p);
                    cout << "Defeat\n";
                    cout << "The updated stocks are:\n" << arm1 << mun1;
                    if (arm1.verificare_cantitate(nr_oameni)) {
                        if (mun1.verificare_munitie(arm1))
                            cout << "Sufficient weapons and ammunition.\n";
                        else
                            cout << "Sufficient weapons, but insufficient ammunition.\n";
                    } else {
                        if (mun1.verificare_munitie(arm1))
                            cout << "Not enough weapons, but enough ammunition.\n";
                        else
                            cout << "Insufficient weapons and ammunition.\n";
                    }

                }
            }
            if (membru.get_misiune() == "strateg") {
                char valori[1001], *p;
                strcpy(valori, (mesaj.get_mesaj()).c_str());
                p = strtok(valori, "_");
                if (p[0] == 'f') {
                    p = strtok(NULL, "_");
                    coord6.determinare_coordonate(stof(p));
                } else {
                    p = strtok(NULL, "_");
                    coord6.set_grade(atoi(p));
                    p = strtok(NULL, "_");
                    coord6.set_minute(atoi(p));
                    p = strtok(NULL, "_");
                    coord6.set_secunde(atoi(p));
                    p = strtok(NULL, "_");
                    coord6.coord_atac(coord6.get_grade(), coord6.get_minute(), coord6.get_secunde(), atoi(p));
                }
                atac2.set_zona(coord6);
                atac2.set_ora(0);
                atac2.set_zi(1);
                atac2.set_luna(1);
                atac2.set_an(1943);
                atac2.set_km(0);
                cout << atac2;
            }
        } else
            cout << "The received message is a trap!\n";
        if (index == 1) {
            mesaj = mesaj2;
            membru = mesaj.get_id();
        }
        if (index == 2) {
            mesaj = mesaj3;
            membru = mesaj.get_id();
        }
        if (index == 3) {
            mesaj = mesaj4;
            membru = mesaj.get_id();
        }
        if (index == 4) {
            mesaj = mesaj5;
            membru = mesaj.get_id();
        }
        if (index == 5) {
            mesaj = mesaj6;
            membru = mesaj.get_id();
        }
        if (index == 6) {
            mesaj = mesaj7;
            membru = mesaj.get_id();
        }
        cout << endl;
    }
    return 0;
}
