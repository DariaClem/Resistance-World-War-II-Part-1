# Proiect1_POO

## Poveste 
În timpul celui de-al Doilea Război Mondial, în Franța ocupată de trupele germane, francezi de toate vârstele s-au unit pentru a slăbi forțele inamicului, atât prin sabotaj, cât și prin operațiuni militare.

Înainte de asedierea Parisului ai studiat criptologia și consideri că ai putea ajuta Rezistența printr-o muncă ascunsă de ochii lumii, dar crucială. Pe un dispozitiv obținut de pe Piața Neagră vrei să centralizezi informațiile despre colegi, atacuri, armament, muniție, coordonatele mesajelor sau a viitoarelor confruntări, dar vrei, de asemenea, să poți verifica autenticitatea unor mesaje primite: sunt mesaje capcane sau sunt trimise de oamenii voștri? 
    
> Jurnal de război
***15 martie 1942***

În această zi primești de la un coleg de încredere un pachet cu mai multe plicuri în el. Fiecare reprezintă, teoretic, mesaje primite de la membrii Rezistenței. Îndatorirea ta este de a verifica fiecare mesaj în parte, trecându-l prin mai multe filtre:
    
* Verifică fiecare mesaj dacă acesta provine dintr-o sursă sigură, întrucât acesta poate fi trimis de inamic pentru a vă atrage într-o capcană.
* Decriptează mesajele folosind cheia dată.
* În funcție de meseria mesagerului, tratezi diferit conținutul mesajului:
  * gestionar_arme: ți se specifică numărul de arme pe care le primești în stoc
  * gestionar_muniție: ți se specifică numărul de cartușe pe care le primești în stoc
  * spion: ți se specifică coordonatele unui atac viitor
  * militar: ți se specifică date despre o confuntare cu inamicul:
    * dacă este înfrângere, ți se precizează pierderile de arme și muniție 
    * dacă este victorie, știi că stocurile de arme și muniție se suplimentează cu un stoc confiscat de la inamic, cunoscut anterior
  * strateg: ți se precizează coordonatele unui atac stabilit pentru începutul anului următor în Paris

> Date tehnice

Se citește de la tastatură numărul de membrii din Rezistență. 

Fiecare obiect este inițializat pentru a ușura procesul de verificare al corectitudinii lui.

Operatorii de citire funcționează, dar nu sunt testați explicit în codul sursă. În cazul utilizării lor, mesajele citite trebuie să nu conțină spații, cuvintele fiind despărțite prin "_". 

> Semnificație funcții:
* _verificare_siguranta_ (clasa _Atacuri_) - verifică dacă atacul plănuit nu are loc la o oră nepotrivită pentru siguranța civililor sau dacă acesta nu are loc în raza capitalei.
* _verificare_autenticitate_ (clasa _Decriptare_) - verifică dacă mesajul primit este autentic. Mesajul este autentic dacă sunt adevărate 2 relații între id-ul persoanei și cheia de decriptare, dar și dacă suma coordonatelor primite este impară.
* _decriptare_mesaj_ (clasa _Decriptare_) - decriptează mesajul primit cu cheia dată prin aplicarea operatorului xor între fiecare literă a mesajului și cheie. 
* _coord_atac_ (clasa _coordonate_) - modifică niște coordonate cu o valoare dată.
* _determinare_coordonate_ (clasa _coordonate_) - determină un set de coordonate după o valore zecimală dată.
* _verificare_cantitate_ (clasa _Armament_) - verifică dacă sunt suficiente arme pentru numărul de oameni citit de la tastatură.
* _verificare_munitie_ (clasa _Munitie_) - verifică dacă sunt suficiente cartușe pentru numărul de arme.
