Návěstní kódy S-COM
===================

Následující kódy podporuje NV-H5B, kopírují
[specifikaci S-COM](https://www.mtb-model.com/elektro/s-com.htm).
Záměrem je zachovat zpětnou kompatibilitu s touto specifikací.

| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.    |
| --- | ------------------------------------------------------- | ------------------ |
| 0   | Stůj                                                    | Č                  |
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

## Jízda podle rozhledových poměrů

Následující kódy zatím NV-H5B nepodporuje a jsou navržené jako kódy rozšiřující.
Tyto kódy umí mj. generovat dekodéry pana Petra Šídla.

| Kód | Návěst hlavního světelného návěstidla                   | Signál hl. náv.    |
| --- | ------------------------------------------------------- | ------------------ |
| 17  | Jízda podle rozhledových poměrů                         | HŽ + PK B          |
| 18  | 40 km/h a jízda podle rozhledových poměrů               | HŽ + PK B + PK DŽ  |
