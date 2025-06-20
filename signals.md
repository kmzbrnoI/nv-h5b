Návěstní kódy S-COM
===================

Následující kódy podporuje NV-H5B, kopírují
[specifikaci S-COM](https://www.mtb-model.com/elektro/s-com.htm).
Záměrem je zachovat zpětnou kompatibilitu s touto specifikací.

| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.    |
| --- | ------------------------------------------------------- | ------------------ |
| 0   | Stůj / Posun zakázán                                    | Č / M *            |
| 1   | Volno                                                   | Z                  |
| 2   | Výstraha                                                | HŽ                 |
| 3   | Očekávejte rychlost 40 km/h                             | PK HŽ              |
| 4   | Rychlost 40 km/h a volno                                | Z + DŽ             |
| 5   | Svítí vše                                               | vše                |
| 6   | Rychlost 40 km/h a výstraha                             | HŽ + DŽ            |
| 7   | Rychlost 40 km/h a očekávejte 40 km/h                   | PK HŽ + DŽ         |
| 8   | Přivolávací návěst                                      | Č + PK B           |
| 9   | Dovolen zajištěný posun                                 | B                  |
| 10  | Dovolen nezajištěný posun                               | Č + B              |
| 11  | Opakování návěsti volno                                 | Z + B              |
| 12  | Opakování návěsti výstraha                              | HŽ + B             |
| 13  | Návěstidlo zhaslé                                       | -                  |
| 14  | Opakování návěsti očekávejte 40 km/h                    | PK HŽ + B          |
| 15  | Rychlost 40 km/h a opakování návěsti Výstraha           | HŽ + B + DŽ        |
| 16  | Rychlost 40 km/h a opakování návěsti očekávejte 40 km/h | PK HŽ + B + DŽ     |

Vysvětlivky:
* PK = pomalu kmitající (33 kmit / min)
* RK = rychle kmitající (66 kmit / min)
* HŽ = horní žlutá
* Z = zelená
* Č = červená
* B = bílá
* M = modrá
* DŽ = dolní žlutá
* HRI = horní rychlostní indikátor

(*) TODO co u návěstidel, které obsahují modrou i červenou?

## Jízda podle rozhledových poměrů

Následující kódy zatím NV-H5B nepodporuje a jsou navržené jako kódy rozšiřující.
Tyto kódy umí mj. generovat dekodéry pana Petra Šídla.

| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.    |
| --- | ------------------------------------------------------- | ------------------ |
| 17  | Jízda podle rozhledových poměrů                         | HŽ + PK B          |
| 18  | 40 km/h a jízda podle rozhledových poměrů               | HŽ + PK B + DŽ     |
| 19  | Jízda vlaku dovolena                                    | PK M               |

## Rychlostní proužky

Následující kódy zatím NV-H5B nepodporuje a jsou navržené jako kódy rozšiřující.
Rychlosti 60 km/h, 80 km/h, 100 km/h mají vlastní kódy, protože jejich předvěst musí
blikat zelenou nebo žlutou barvou.
Oproti tomu omezení rychlosti dané spodním rychlostním indikátorem je předvěstěno
vždy také rychlostním indikátorem. Proto není potřeba mít kódy pro konkrétní rychlosti,
stačí svázat rychlostní indikátor na hlavním návěstidle a na předvěsti.
Předpokládá se, že S-COM přijímač bude umožňovat až 2 rychlostní indikátory
(2 samostatné výstupy) `RIA` a `RIB`. Podle potřeby mohou být:

1. oba horní
2. jeden horní, druhý dolní
3. oba dolní


| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.    |
| --- | ------------------------------------------------------- | ------------------ |
| 20  | Očekávejte rychlost 60 km/h                             | RK HŽ              |
| 21  | Očekávejte rychlost 80 km/h                             | PK Z               |
| 22  | Očekávejte rychlost 100 km/h                            | RK Z               |
| 23  | Očekávejte rychlost zobrazenou na RIA                   |                    |
| 24  | Očekávejte rychlost zobrazenou na RIB                   |                    |
| -   | -                                                       |                    |
| 25  | Rychlost 60 km/h a volno                                |                    |
| 26  | Rychlost 80 km/h a volno                                |                    |
| 27  | Rychlost 100 km/h a volno                               |                    |
| 28  | Rychlost zobrazená na RIA a volno                       |                    |
| 29  | Rychlost zobrazená na RIB a volno                       |                    |
| -   | -                                                       |                    |
| 30  | Rychlost 60 km/h a výstraha                             |                    |
| 31  | Rychlost 80 km/h a výstraha                             |                    |
| 32  | Rychlost 100 km/h a výstraha                            |                    |
| 33  | Rychlost zobrazená na RIA a výstraha                    |                    |
| 34  | Rychlost zobrazená na RIB a výstraha                    |                    |
| -   | -                                                       |                    |
| 35  | Rychlost 60 km/h a očekávejte 40 km/h                   |                    |
| 36  | Rychlost 80 km/h a očekávejte 40 km/h                   |                    |
| 37  | Rychlost 100 km/h a očekávejte 40 km/h                  |                    |
| 38  | Rychlost zobrazená na RIA a očekávejte 40 km/h          |                    |
| 39  | Rychlost zobrazená na RIB a očekávejte 40 km/h          |                    |
| -   | -                                                       |                    |
| 40  | Rychlost 40 km/h a očekávejte 60 km/h                   |                    |
| 41  | Rychlost 60 km/h a očekávejte 60 km/h                   |                    |
| 42  | Rychlost 80 km/h a očekávejte 60 km/h                   |                    |
| 43  | Rychlost 100 km/h a očekávejte 60 km/h                  |                    |
| 44  | Rychlost zobrazená na RIA a očekávejte 60 km/h          |                    |
| 45  | Rychlost zobrazená na RIB a očekávejte 60 km/h          |                    |
| -   | -                                                       |                    |
| 46  | Rychlost 40 km/h a očekávejte 80 km/h                   |                    |
| 47  | Rychlost 60 km/h a očekávejte 80 km/h                   |                    |
| 48  | Rychlost 80 km/h a očekávejte 80 km/h                   |                    |
| 49  | Rychlost 100 km/h a očekávejte 80 km/h                  |                    |
| 50  | Rychlost zobrazená na RIA a očekávejte 80 km/h          |                    |
| 51  | Rychlost zobrazená na RIB a očekávejte 80 km/h          |                    |
| -   | -                                                       |                    |
| 52  | Rychlost 40 km/h a očekávejte 100 km/h                  |                    |
| 53  | Rychlost 60 km/h a očekávejte 100 km/h                  |                    |
| 54  | Rychlost 80 km/h a očekávejte 100 km/h                  |                    |
| 55  | Rychlost 100 km/h a očekávejte 100 km/h                 |                    |
| 56  | Rychlost zobrazená na RIA a očekávejte 100 km/h         |                    |
| 57  | Rychlost zobrazená na RIB a očekávejte 100 km/h         |                    |
| -   | -                                                       |                    |
| 58  | Rychlost 40 km/h a očekávejte rychlost zobraz. na RIA   |                    |
| 59  | Rychlost 60 km/h a očekávejte rychlost zobraz. na RIA   |                    |
| 60  | Rychlost 80 km/h a očekávejte rychlost zobraz. na RIA   |                    |
| 61  | Rychlost 100 km/h a očekávejte rychlost zobraz. na RIA  |                    |
| 62  | Rychlost RIB a očekávejte rychlost zobraz. na RIA       |                    |
| -   | -                                                       |                    |
| 63  | Rychlost 40 km/h a očekávejte rychlost zobraz. na RIB   |                    |
| 64  | Rychlost 60 km/h a očekávejte rychlost zobraz. na RIB   |                    |
| 65  | Rychlost 80 km/h a očekávejte rychlost zobraz. na RIB   |                    |
| 66  | Rychlost 100 km/h a očekávejte rychlost zobraz. na RIB  |                    |
| 67  | Rychlost RIA a očekávejte rychlost zobraz. na RIB       |                    |
| -   | -                                                       |                    |
| 68  | Opakování návěsti Očekávejte rychlost 60 km/h           |                    |
| 69  | Opakování návěsti Očekávejte rychlost 80 km/h           |                    |
| 70  | Opakování návěsti Očekávejte rychlost 100 km/h          |                    |
| 71  | Opakování návěsti Očekávejte rychlost zobraz. na RIA    |                    |
| 72  | Opakování návěsti Očekávejte rychlost zobraz. na RIB    |                    |
| 73  | Rychlost zobrazená na RIA a opakování návěsti Výstraha  |                    |
| 74  | Rychlost zobrazená na RIB a opakování návěsti Výstraha  |                    |
| 75  | Rychlost 60 km/h a opakování návěsti Výstraha           |                    |
| 76  | Rychlost 80 km/h a opakování návěsti Výstraha           |                    |
| 77  | Rychlost 40 km/h a opak. návěsti Oček. rych. 60 km/h    |                    |
| 78  | Rychlost 40 km/h a opak. návěsti Oček. rych. 80 km/h    |                    |
| 79  | Rychlost 40 km/h a opak. návěsti Oček. rych. 100 km/h   |                    |
| 80  | Rychlost 40 km/h a opak. návěsti Oček. rych. RIA        |                    |
| 81  | Rychlost 40 km/h a opak. návěsti Oček. rych. RIB        |                    |

