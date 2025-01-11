# Mate_Zoko_Seminar_OOP
Seminarski zadatak-Connect four


Ovaj projekt implementira igru **Connect Four** u programskom jeziku C++. Projekt je osmišljen kako bi omogućio dvama ljudskim igračima da igraju jedan protiv drugoga na terminalu. 

## Značajke

- Dva igrača (*Player*) mogu igrati igru, svaki s različitim simbolima ('X' i 'O').
- **Igra** koristi 6x7 ploču koja je implementirana pomoću `std::vector`.
- Provjera pobjede uključuje horizontalne, vertikalne i dijagonalne kombinacije.
- Prikaz ploče u terminalu koristi znak '.' za prazna mjesta.
- Igra provjerava valjanost poteza i sprječava ilegalne poteze.
- Igra završava kada jedan igrač pobijedi ili kada je ploča puna, što rezultira neriješenim ishodom.

## Struktura Koda

- **`Player` klasa**: Osnovna klasa koja definira zajedničke funkcionalnosti svih igrača.
- **`HumanPlayer` klasa**: Izvedena klasa iz `Player` koja implementira unos igrača putem terminala.
- **`Game` klasa**: Upravljanje pločom, provjera poteza, provjera pobjede i vođenje glavne petlje igre.
- **`main` funkcija**: Inicijalizira igrače i pokreće igru.

## Korištenje

Da biste pokrenuli igru, jednostavno kompajlirajte i pokrenite `main.cpp`:

```sh
g++ main.cpp -o connect_four
./connect_four

