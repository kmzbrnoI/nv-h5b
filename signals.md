Návěstní kódy S-COM
===================

Následující kódy podporuje NV-H5B, kopírují
[specifikaci S-COM](https://www.mtb-model.com/elektro/s-com.htm).
Záměrem je zachovat zpětnou kompatibilitu s touto specifikací.

| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.    | Návěst předvěsti |
| --- | ------------------------------------------------------- | ------------------ | ---------------- |
| 0   | Stůj / Posun zakázán                                    | Č / M *            | 2/12             |
| 1   | Volno                                                   | Z                  | 1/11             |
| 2   | Výstraha                                                | HŽ                 | 1/11             |
| 3   | Očekávejte rychlost 40 km/h                             | PK HŽ              | 1/11             |
| 4   | Rychlost 40 km/h a volno                                | Z + DŽ             | 3/14             |
| 5   | Svítí vše                                               | vše                | 5                |
| 6   | Rychlost 40 km/h a výstraha                             | HŽ + DŽ            | 3/14             |
| 7   | Rychlost 40 km/h a očekávejte 40 km/h                   | PK HŽ + DŽ         | 3/14             |
| 8   | Přivolávací návěst                                      | Č + PK B           | 2/12             |
| 9   | Dovolen zajištěný posun                                 | B                  | 2/12             |
| 10  | Dovolen nezajištěný posun                               | Č + B              | 2/12             |
| 11  | Opakování návěsti volno                                 | Z + B              | 1/11             |
| 12  | Opakování návěsti výstraha                              | HŽ + B             | 2/12             |
| 13  | Návěstidlo zhaslé                                       | -                  | 13               |
| 14  | Opakování návěsti očekávejte 40 km/h                    | PK HŽ + B          | 3/14             |
| 15  | Rychlost 40 km/h a opakování návěsti Výstraha           | HŽ + B + DŽ        | 2/12             |
| 16  | Rychlost 40 km/h a opakování návěsti očekávejte 40 km/h | PK HŽ + B + DŽ     | 3/14             |

Vysvětlivky:
* PK = pomalu kmitající (54 kmit / min)
* RK = rychle kmitající (108 kmit / min)
* HŽ = horní žlutá
* Z = zelená
* Č = červená
* B = bílá
* M = modrá
* DŽ = dolní žlutá
* HZP = horní zelený proužek
* DZP = dolní zelený proužek
* ŽP = žlutý proužek
* RIA = rychlostní indikátor A
* RIB = rychlostní indikátor B

(*) TODO co u návěstidel, které obsahují modrou i červenou?

## Jízda podle rozhledových poměrů

Následující kódy zatím NV-H5B nepodporuje a jsou navržené jako kódy rozšiřující.
Tyto kódy umí mj. generovat dekodéry pana Petra Šídla.

| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.      | Návěst předvěsti |
| --- | ------------------------------------------------------- | -------------------- | ---------------- |
| 17  | Jízda podle rozhledových poměrů                         | HŽ + PK B            | 2/12             |
| 18  | 40 km/h a jízda podle rozhledových poměrů               | HŽ + PK B + DŽ       | ?                |
| 19  | RIA a jízda podle rozhledových poměrů                   | HŽ + PK B + DŽ + RIA | ?                |
| 20  | Jízda vlaku dovolena                                    | PK M                 | ?                |

## Rychlostní proužky a indikátory

Následující kódy zatím NV-H5B nepodporuje a jsou navržené jako kódy rozšiřující.

Rychlosti 60 km/h, 80 km/h, 100 km/h mají vlastní kódy, protože jejich předvěst musí
blikat zelenou nebo žlutou barvou.

Oproti tomu omezení rychlosti dané spodním rychlostním indikátorem je předvěstěno
vždy také rychlostním indikátorem. Proto není potřeba mít kódy pro konkrétní rychlosti,
stačí svázat rychlostní indikátor na hlavním návěstidle a na předvěsti.
Předpokládá se, že S-COM přijímač bude umožňovat až 2 rychlostní indikátory
(2 samostatné výstupy) `RIA` a `RIB`. Podle situace mohou být fyzické výstupy
zapojeny:

1. oba výstupy na horní rychlostní indikátor,
2. jeden výstup na horní, druhý na dolní rychlostní indikátor,
3. oba výstupy na dolní rychlostní indikátor.


| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.             | Návěst předvěsti |
| --- | ------------------------------------------------------- | --------------------------- | ---------------- |
| 20  | Očekávejte rychlost 60 km/h                             | RK HŽ                       |                  |
| 21  | Očekávejte rychlost 80 km/h                             | PK Z                        |                  |
| 22  | Očekávejte rychlost 100 km/h                            | RK Z                        |                  |
| 23  | Očekávejte rychlost zobrazenou na RIA                   | RK Z + RIA                  |                  |
| 24  | Očekávejte rychlost zobrazenou na RIB                   | RK Z + RIB                  |                  |
| -   | -                                                       |                             |                  |
| 25  | Rychlost 60 km/h a volno                                | Z + DŽ + ŽP                 |                  |
| 26  | Rychlost 80 km/h a volno                                | Z + DŽ + HZP                |                  |
| 27  | Rychlost 100 km/h a volno                               | Z + DŽ + HZP + DZP          |                  |
| 28  | Rychlost zobrazená na RIA a volno                       | Z + DŽ + RIA                |                  |
| 29  | Rychlost zobrazená na RIB a volno                       | Z + DZ + RIB                |                  |
| -   | -                                                       |                             |                  |
| 30  | Rychlost 60 km/h a výstraha                             | HŽ + DŽ + ŽP                |                  |
| 31  | Rychlost 80 km/h a výstraha                             | HŽ + DŽ + HZP               |                  |
| 32  | Rychlost 100 km/h a výstraha                            | HŽ + DŽ + HZP + DZP         |                  |
| 33  | Rychlost zobrazená na RIA a výstraha                    | HŽ + DŽ + RIA               |                  |
| 34  | Rychlost zobrazená na RIB a výstraha                    | HŽ + DŽ + RIB               |                  |
| -   | -                                                       |                             |                  |
| 35  | Rychlost 60 km/h a očekávejte 40 km/h                   | PK HŽ + DŽ + ŽP             | 20/68            |
| 36  | Rychlost 80 km/h a očekávejte 40 km/h                   | PK HŽ + DŽ + HZP            | 21/69            |
| 37  | Rychlost 100 km/h a očekávejte 40 km/h                  | PK HŽ + DŽ + HZP + DZP      | 22/70            |
| 38  | Rychlost zobrazená na RIA a očekávejte 40 km/h          | PK HŽ + DŽ + RIA            | 23/71            |
| 39  | Rychlost zobrazená na RIB a očekávejte 40 km/h          | PK HŽ + DŽ + RIB            | 24/72            |
| -   | -                                                       |                             |                  |
| 40  | Rychlost 40 km/h a očekávejte 60 km/h                   | RK HŽ + DŽ                  |                  |
| 41  | Rychlost 60 km/h a očekávejte 60 km/h                   | RK HŽ + DŽ + ŽP             |                  |
| 42  | Rychlost 80 km/h a očekávejte 60 km/h                   | RK HŽ + DŽ + HZP            |                  |
| 43  | Rychlost 100 km/h a očekávejte 60 km/h                  | RK HŽ + DŽ + HZP + DZP      |                  |
| 44  | Rychlost zobrazená na RIA a očekávejte 60 km/h          | RK HŽ + DŽ + RIA            |                  |
| 45  | Rychlost zobrazená na RIB a očekávejte 60 km/h          | RK HŽ + DŽ + RIB            |                  |
| -   | -                                                       |                             |                  |
| 46  | Rychlost 40 km/h a očekávejte 80 km/h                   | PK Z + DŽ                   |                  |
| 47  | Rychlost 60 km/h a očekávejte 80 km/h                   | PK Z + DŽ + ŽP              |                  |
| 48  | Rychlost 80 km/h a očekávejte 80 km/h                   | PK Z + DŽ + HZP             |                  |
| 49  | Rychlost 100 km/h a očekávejte 80 km/h                  | PK Z + DŽ + HZP + DZP       |                  |
| 50  | Rychlost zobrazená na RIA a očekávejte 80 km/h          | PK Z + DŽ + RIA             |                  |
| 51  | Rychlost zobrazená na RIB a očekávejte 80 km/h          | PK Z + DŽ + RIB             |                  |
| -   | -                                                       |                             |                  |
| 52  | Rychlost 40 km/h a očekávejte 100 km/h                  | RK Z + DŽ                   |                  |
| 53  | Rychlost 60 km/h a očekávejte 100 km/h                  | RK Z + DŽ + ŽP              |                  |
| 54  | Rychlost 80 km/h a očekávejte 100 km/h                  | RK Z + DŽ + HZP             |                  |
| 55  | Rychlost 100 km/h a očekávejte 100 km/h                 | RK Z + DŽ + HZP + DZP       |                  |
| 56  | Rychlost zobrazená na RIA a očekávejte 100 km/h         | RK Z + DŽ + RIA             |                  |
| 57  | Rychlost zobrazená na RIB a očekávejte 100 km/h         | RK Z + DŽ + RIB             |                  |
| -   | -                                                       |                             |                  |
| 58  | Rychlost 40 km/h a očekávejte rychlost zobraz. na RIA   | RIA + RK Z + DŽ             |                  |
| 59  | Rychlost 60 km/h a očekávejte rychlost zobraz. na RIA   | RIA + RK Z + DŽ + ŽP        |                  |
| 60  | Rychlost 80 km/h a očekávejte rychlost zobraz. na RIA   | RIA + RK Z + DŽ + HZP       |                  |
| 61  | Rychlost 100 km/h a očekávejte rychlost zobraz. na RIA  | RIA + RK Z + DŽ + HZP + DZP |                  |
| 62  | Rychlost RIB a očekávejte rychlost zobraz. na RIA       | RIA + RK Z + DŽ + RIB       |                  |
| -   | -                                                       |                             |                  |
| 63  | Rychlost 40 km/h a očekávejte rychlost zobraz. na RIB   | RIB + RK Z + DŽ             |                  |
| 64  | Rychlost 60 km/h a očekávejte rychlost zobraz. na RIB   | RIB + RK Z + DŽ + ŽP        |                  |
| 65  | Rychlost 80 km/h a očekávejte rychlost zobraz. na RIB   | RIB + RK Z + DŽ + HZP       |                  |
| 66  | Rychlost 100 km/h a očekávejte rychlost zobraz. na RIB  | RIB + RK Z + DŽ + HZP + DZP |                  |
| 67  | Rychlost RIA a očekávejte rychlost zobraz. na RIB       | RIB + RK Z + DŽ + RIA       |                  |
| -   | -                                                       |                             |                  |
| 68  | Opakování návěsti Očekávejte rychlost 60 km/h           | RK HŽ + B                   |                  |
| 69  | Opakování návěsti Očekávejte rychlost 80 km/h           | PK Z + B                    |                  |
| 70  | Opakování návěsti Očekávejte rychlost 100 km/h          | RK Z + B                    |                  |
| 71  | Opakování návěsti Očekávejte rychlost zobraz. na RIA    | RIA + RK Z + B              |                  |
| 72  | Opakování návěsti Očekávejte rychlost zobraz. na RIB    | RIA + RK Z + B              |                  |
| 73  | Rychlost zobrazená na RIA a opakování návěsti Výstraha  | HŽ + B + DŽ + RIA           |                  |
| 74  | Rychlost zobrazená na RIB a opakování návěsti Výstraha  | HŽ + B + DŽ + RIB           |                  |
| 75  | Rychlost 60 km/h a opakování návěsti Výstraha           | HŽ + B + DŽ + ŽP            |                  |
| 76  | Rychlost 80 km/h a opakování návěsti Výstraha           | HŽ + B + DŽ + HZP           |                  |
| 77  | Rychlost 40 km/h a opak. návěsti Oček. rych. 60 km/h    | RK HŽ + DŽ + ŽP             |                  |
| 78  | Rychlost 40 km/h a opak. návěsti Oček. rych. 80 km/h    | PK Z + DŽ + HZP             |                  |
| 79  | Rychlost 40 km/h a opak. návěsti Oček. rych. 100 km/h   | RK Z + DŽ + HZP + DZP       |                  |
| 80  | Rychlost 40 km/h a opak. návěsti Oček. rych. RIA        | RIA + RK Z + DŽ + RIA       |                  |
| 81  | Rychlost 40 km/h a opak. návěsti Oček. rych. RIB        | RIB + RK Z + DŽ + RIB       |                  |

Nevýhodou univerzálních výstupů `RIA` a `RIB` je, že kód návěsti nepřenáší přímo
dovolenou rychlost.

Nevýhodou navrženého řešení je omezení rychlostních indikátorů každého
návěstidla na dva.

S-COM přijímač by měl mít 10 výstupů (HŽ, Z, Č, B, DŽ, ŽP, HZP, DZP, RIA, RIB).
