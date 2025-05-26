Acesta este un platformer simplu scris in C++ folosind biblioteca SFML 3.0.
Jocul contine:
	- Un jucator care:
		- Se poate misca cu WASD
		- Poate sari
		- Poate efectua un dash
		- Are viata care scade atunci cand cade de pe harta
		- Este afectat de gravitatie 
		- Detecteaza si gestioneaza coliziuni cu obiecte statice (de tip StaticObject), în special platforme (de tip Platform)
	- Un manager de stari care schimba intre:
		- Meniu principal 
		- Niveluri ale jocului
		- Ecran de finalizare (victorie sau infrangere)

Am ales să nu descriu fiecare clasă direct în README, ci să pun comentarii în fișierele .h, unde sunt declarate clasele.

Respectarea cerintelor proiectului 2:
	- Toate clasele sunt separate în .cpp și .h și nu am folosit nicăieri using namespace std.
	- Din clasa GameState sunt derivate MenuState, LevelState și GameEndState.
	- Entity (pentru obiecte dinamice), StaticObject (pentru obiecte statice) și GameState (pentru stările jocului) sunt clase virtuale și sunt 
	apelate prin pointeri la clasa de bază (de exemplu unde există platforme am folosit de fiecare dată un vector de tip std::unique_ptr<StaticObject>).
	- Obiectele de tip Entity implementează clone și am folosit peste tot std::unique_ptr, care blochează copierea implicită.
	- Folosesc dynamic_cast acolo unde este nevoie de downcast controlat între clase (ex: Entity spre Player dacă este necesar).
	- Toate obiectele dinamice (Entity, StaticObject, Texts, Button) sunt administrate cu smart pointers (std::unique_ptr).
	- Am creat o ierarhie proprie de excepții (GameException, FontLoadException, LevelLoadException, ResourceLoadException) care derivă din 
	std::exception, cu throw în constructori și try/catch în main.
	- Am folosit atribute statice acolo unde are sens, de exemplu pentru gravitatia care afecteaza jucatorul.
	- STL este folosit extensiv (vectori, stringuri, optional, smart pointeri).
	- Am folosit const peste tot unde este necesar, atât la parametrii funcțiilor cât și la metode.
	- Funcțiile principale sunt de nivel înalt (ex: update(), render(), handleEvent()) și am evitat folosirea de settere/gettere low-level inutile.

Respectarea cerintelor proiectului 3:
	- Am transformat clasa Texts într-o clasă șablon care acceptă orice tip convertibil la text.
	- Am modificat metoda streamText, care acum generează textul ce urmează să fie afișat pe ecran, folosind un prefix (de tip T) și o valoare dinamică.
	- ObjectFactory<T>::createObjectsForLevel(...) este o funcție șablon statică care creează obiecte în funcție de nivel.
		- Funcția este specializată pentru:
			- StaticObject
			- Texts
	- Design pattern-uri utilizate:
		- Singleton: 
			- GameStateManager este implementat ca singleton, permițând acces global la managerul de stări, fără a fi nevoie să fie transmis prin constructori.
		- Factory: 
			- ObjectFactory<T> este utilizată pentru a crea dinamic obiecte de tip StaticObject și Texts, în funcție de nivel și parametri.
		- Strategy: 
			- FallPenaltyStrategy cu 3 clase derivate: EasyPenalty, MediumPenalty și HardPenalty; acestea aplică o logică diferită de penalizare, în funcție de dificultatea jocului.
		- State: 
			- Am implementat o ierarhie de stări prin clasa abstractă GameState și clasele derivate MenuState, LevelState și GameEndState. GameStateManager comută între aceste 
			stări în timpul execuției, permițând comportamente diferite pentru meniu, joc sau ecranul final, fără a modifica structura principală a codului.

Surse de documentatie:
	- Pentru SFML m-am bazat pe documentatia oficiala
	- Am mai cautat informatii despre STL pe internet, dar nu pot preciza o sursa propriu zisa
	- Pentru conceptele de POO am consultat cursurile si cateva forum-uri

GitHub: https://github.com/aalex069/POO