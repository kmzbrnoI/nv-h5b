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

## Rychlostní proužky

Následující kódy zatím NV-H5B nepodporuje a jsou navržené jako kódy rozšiřující.

| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.    |
| --- | ------------------------------------------------------- | ------------------ |
| 19  | Očekávejte rychlost 60 km/h                             | RK HŽ              |
| 20  | Očekávejte rychlost 80 km/h                             | PK Z               |
| 21  | Očekávejte rychlost 100 km/h                            | RK Z               |
| 22  | Očekávejte rychlost 120 km/h                            | HRI                |
| 23  | Rychlost 60 km/h a volno                                |                    |
| 24  | Rychlost 80 km/h a volno                                |                    |
| 25  | Rychlost 100 km/h a volno                               |                    |
| 26  | Rychlost 120 km/h a volno                               |                    |
| -   | -                                                       |                    |
| 27  | Rychlost 60 km/h a výstraha                             |                    |
| 28  | Rychlost 80 km/h a výstraha                             |                    |
| 29  | Rychlost 100 km/h a výstraha                            |                    |
| 30  | Rychlost 120 km/h a výstraha                            |                    |
| -   | -                                                       |                    |
| 31  | Rychlost 60 km/h a očekávejte 40 km/h                   |                    |
| 32  | Rychlost 80 km/h a očekávejte 40 km/h                   |                    |
| 33  | Rychlost 100 km/h a očekávejte 40 km/h                  |                    |
| 34  | Rychlost 120 km/h a očekávejte 40 km/h                  |                    |
| -   | -                                                       |                    |
| 35  | Rychlost 40 km/h a očekávejte 60 km/h                   |                    |
| 36  | Rychlost 60 km/h a očekávejte 60 km/h                   |                    |
| 37  | Rychlost 80 km/h a očekávejte 60 km/h                   |                    |
| 38  | Rychlost 100 km/h a očekávejte 60 km/h                  |                    |
| 39  | Rychlost 120 km/h a očekávejte 60 km/h                  |                    |
| -   | -                                                       |                    |
| 40  | Rychlost 40 km/h a očekávejte 80 km/h                   |                    |
| 41  | Rychlost 60 km/h a očekávejte 80 km/h                   |                    |
| 42  | Rychlost 80 km/h a očekávejte 80 km/h                   |                    |
| 43  | Rychlost 100 km/h a očekávejte 80 km/h                  |                    |
| 44  | Rychlost 120 km/h a očekávejte 80 km/h                  |                    |
| -   | -                                                       |                    |
| 45  | Rychlost 40 km/h a očekávejte 100 km/h                  |                    |
| 46  | Rychlost 60 km/h a očekávejte 100 km/h                  |                    |
| 47  | Rychlost 80 km/h a očekávejte 100 km/h                  |                    |
| 48  | Rychlost 100 km/h a očekávejte 100 km/h                 |                    |
| 49  | Rychlost 120 km/h a očekávejte 100 km/h                 |                    |
| -   | -                                                       |                    |
| 50  | Rychlost 40 km/h a očekávejte 120 km/h                  |                    |
| 51  | Rychlost 60 km/h a očekávejte 120 km/h                  |                    |
| 52  | Rychlost 80 km/h a očekávejte 120 km/h                  |                    |
| 53  | Rychlost 100 km/h a očekávejte 120 km/h                 |                    |
| 54  | Rychlost 120 km/h a očekávejte 120 km/h                 |                    |
| -   | -                                                       |                    |
| 55  | Opakování návěsti Očekávejte rychlost 60 km/h           |                    |
| 56  | Opakování návěsti Očekávejte rychlost 80 km/h           |                    |
| 57  | Opakování návěsti Očekávejte rychlost 100 km/h          |                    |
| 58  | Opakování návěsti Očekávejte rychlost 120 km/h          |                    |
| 59  | Rychlost 30 km/h a opakování návěsti Výstraha           |                    |
| 60  | Rychlost 40 km/h a opak. návěsti Oček. rych. 60 km/h    |                    |
| 61  | Rychlost 40 km/h a opak. návěsti Oček. rych. 80 km/h    |                    |
| 62  | Rychlost 40 km/h a opak. návěsti Oček. rych. 100 km/h   |                    |
| 63  | Rychlost 40 km/h a opak. návěsti Oček. rych. 120 km/h   |                    |

TODO: rychlostní indikátory nad i pod návěstidlem
