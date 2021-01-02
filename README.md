# Papild_OPP
### užduotis: 
* Suskaičiuokite, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tekstą galite paimti iš bet kur, pvz.: Vikipediją straipsnį apie Vilnių (Geriau kad būtu kitoks tekstas, ne mažiau 1000 žodžių). Tuomet realizacijos output'e (išoriniame faile) išveskite skirtingus žodžius (kableliai, taškai ir kiti skyrybos ženklai nėra žodžiu dalis!), kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo.
* Sukurkite cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas.
* URL adresų suradimas Jūsų tekste. Kaip ir pirmos užduoties atveju, tekstą galite paimti iš bet kur, račiau būtina, kad tame tekste būtų bent keli URL'ai, pateikti "pilnu" https://www.vu.lt/ ar "sutrumpintu" pavidalu: www.vu.lt. Jūsų tikslas, iš to teksto išrinkti visus šiuos URL'us ir grąžiai atspausdinti ekrane (ar išvesti į failą)!
### Realizacija
* Paleidus programą: įvedame "1"
* Programa priima .txt failą "straipsnis.txt". Išveda visus žodžius, kurie pasikartojo daugiau nei 1 kartą failo tekste ir sukuria .csv failą: "1isvestis.csv".
* Sukuria  "cross-reference" lentelę, kurioje stulpeliai yra žodžiai pasikartojantys daugiau nei kartą tekste, o eilutės yra "eilutės nr." tekste. Jeigu šis žodis pasirodo eilutėje, tai susikirtimo taške įrašoma "1", jeigu ne "0". Lentelė išvedama į "lentele.csv" failą.
* Pabaigoje atspausdinama visi url esantys tekste. Pastaba: url atspausdinami pagal tokią reguliąją išraišką: "\S*www\.\S+".
