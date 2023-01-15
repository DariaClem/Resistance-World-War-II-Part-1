### Object-oriented programming 🖥️
# Resistance coordination in the World War II

## Story 
During World War II, in France occupied by German troops, French people of all ages united to weaken the enemy's forces, both through sabotage and military operations.

Before the siege of Paris, you studied cryptology and believe that you could help the Resistance with a job hidden from the world's eyes, but crucial. On a device obtained from the Black Market, you want to centralize information about colleagues, attacks, weapons, ammunition, the coordinates of messages or future confrontations, but you also want to be able to check the authenticity of some received messages: are they trap messages or are they sent by your people?

> War diary
***March 15, 1942***

On this day you receive from a trusted colleague a package with several envelopes in it. Each one theoretically represents messages received from members of the Resistance. Your duty is to check each message individually by passing it through several filters:

* Check every message that it is from a safe source, as it may be sent by the enemy to lure you into a trap.
* Decrypt messages using the given key.
* Depending on the job of the messenger, you treat the content of the message differently:
  * gestionar_arme (weapons manager): you are specified the number of weapons you receive in stock
  * gestionar_muniție (ammunition manager): you are specified the number of cartridges you receive in stock
  * spion (spy): you are given the coordinates of a future attack
  * militar (soldier): you are given data about an enemy encounter:
    * if it's defeat, you're given weapon and ammo losses
    * if it is victory, you know that stocks of weapons and ammunition are supplemented by a previously known stock seized from the enemy
  * strateg (strategist): you are given the coordinates of an attack set for early next year in Paris

> Technical data

The input is the number of people from the Resistance.

Each object is initialized to ease the process of checking its correctness.

The input operators work, but are not explicitly tested in the source code. When using them for objects of type _Decryption_ and _People_, the input must not contain spaces, words being separated by "_".

> Function meaning:
* _verificare_siguranta_ (_Atacuri_ class) - verify that the planned attack does not take place at an inappropriate time for the safety of civilians or that it does not take place within the radius of the capital.
* _verificare_autenticitate_ (_Decriptare_ class) - verify that the received message is genuine. The message is authentic if 2 relationships between the person's id and the decryption key are true, but also if the sum of the coordinates received is odd.
* _decriptare_mesaj_ (_Decriptare_ class) - decrypts the received message with the given key by applying the xor operator between each letter of the message and the key.
* _coord_atac_ (_coordonate_ class) - modifies some coordinates with a given value.
* _determinare_coordonate_ (_coordonate_ class) - determines a set of coordinates by a given decimal value.
* _verificare_cantitate_ (_Armament_ class) - check if there are enough weapons for the number of people.
* _verificare_munitie_ (_Munitie_ class) - check if there are enough cartridges for the number of guns.



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

Operatorii de citire funcționează, dar nu sunt testați explicit în codul sursă. În cazul utilizării lor pentru obiecte de tip _Decriptare_ și _Oameni_, mesajele citite trebuie să nu conțină spații, cuvintele fiind despărțite prin "_". 

> Semnificație funcții:
* _verificare_siguranta_ (clasa _Atacuri_) - verifică dacă atacul plănuit nu are loc la o oră nepotrivită pentru siguranța civililor sau dacă acesta nu are loc în raza capitalei.
* _verificare_autenticitate_ (clasa _Decriptare_) - verifică dacă mesajul primit este autentic. Mesajul este autentic dacă sunt adevărate 2 relații între id-ul persoanei și cheia de decriptare, dar și dacă suma coordonatelor primite este impară.
* _decriptare_mesaj_ (clasa _Decriptare_) - decriptează mesajul primit cu cheia dată prin aplicarea operatorului xor între fiecare literă a mesajului și cheie. 
* _coord_atac_ (clasa _coordonate_) - modifică niște coordonate cu o valoare dată.
* _determinare_coordonate_ (clasa _coordonate_) - determină un set de coordonate după o valore zecimală dată.
* _verificare_cantitate_ (clasa _Armament_) - verifică dacă sunt suficiente arme pentru numărul de oameni citit de la tastatură.
* _verificare_munitie_ (clasa _Munitie_) - verifică dacă sunt suficiente cartușe pentru numărul de arme.
