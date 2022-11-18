# BNMO - IF2110_TB_01_B
With the viral video on toktok, Indra and Doni are willing to meet Siska Kol and ask her to have some dinner together. Unfortunately, Indra doesn't know how to cook at all. So he asks BNMO (his robot game) to prepare that dinner, but BNMO also doesn't have any idea about cooking some delicious food. Your job is to help BNMO develop an app that would help him to cook delicious food.

BNMO is CLI (Command Line Interface) Game that we made using C language. This game includes a lot of data structures and also Abstract Data Types (ADT) that we made ourselves. Some of them are Stack, Queue, Tree, and many more. The purpose of the game is to help the player to order food and cook food with some delicious recipes from mama.

## Pre-Requisite
- CMake https://cmake.org/download/
- Make https://gnuwin32.sourceforge.net/packages/make.htm
- MinGW
- For Windows user, don't forget to include those 3 in your env PATH

## How To Run
1. Clone this repository
2. Type `start.bat` on your terminal/ double click on `start.bat` file
3. If you want to delete your build, type `start.bat clean` on your terminal
4. If you want to change configuration file for the game go to `config/` 

## Member Lists
| Nama                           |   NIM    |                                            Workload Management                                                 |
| ------------------------------ | :------: | :------------------------------------------------------------------------------------------------------------: |
| Muhammad Hanan                 | 13521041 | Debugging, ADT list statik, ADT list dinamis, ADT map, ADT point,  utils, laporan.                             |
| M. Farrel Danendra Rachim      | 13521048 | Laporan (sebagian besar), Stack & UNDO/REDO, ADT List Dinamik, ADT State, ADT Simulator, merapikan kode        |
| Muhammad Bangkit Dwi Cahyono	 | 13521055 | ADT Makanan, ADT Mesin Karakter & Kata, struktur kode, alur aplikasi, ADT color, game, utils, debugging, file konfigurasi, membuat command, merapikan kode, membuat size makanan dan waktu pengolahan makanan, interface, laporan.                                         |
| Mutawally Nawwar               | 13521065 | ADT Tree, ADT Time, laporan, ADT Set, rekomendasi makanan.                                                     |
| Louis Caesa Kesuma             | 13521069 | ADT Simulator, kulkas, prioqueue, infotype, mekanisme penyimpanan dan pengambilan makanan kulkas, mekanisme wait untuk inventory dan delivery list, mekanisme notifikasi, mekanisme notifikasi saat undo/redo, debugging, laporan.                                                  |

## Features

| Feature                        | Status            |
| ------------------------------ | ----------------- |
| `START`                        | &#10004;          |
| `EXIT`                         | &#10004;          |
| `MOVE`                         | &#10004;          |
| `BUY`                          | &#10004;          |
| `FRY`                          | &#10004;          |
| `CHOP`                         | &#10004;          |
| `BOIL`                         | &#10004;          |
| `MIX`                          | &#10004;          |
| `WAIT`                         | &#10004;          |
| `INVENTORY`                    | &#10004;          |
| `DELIVERY`                     | &#10004;          |
| `CATALOG`                      | &#10004;          |
| `COOKBOOK`                     | &#10004;          |
| `UNDO`                         | &#10004;          |
| `REDO`                         | &#10004;          |
| `MASUKKULKAS`                  | &#10004;          |
| `KELUARKULKAS`                 | &#10004;          |
| `KULKAS`                       | &#10004;          |
| `REKOMENDASI`                  | &#10004;          |
| `HELP`                         | &#10004;          |
| `EXIT`                         | &#10004;          |

## Disclaimer
- Please use MinGW if you want to start the batch file, if you want to use MSYS change the `start.bat` file (use `make` instead of `mingw32-make` and change any `MinGW` to `MSYS`) and add `C:\MinGW\msys\1.0\bin` to your env PATH
- https://stackoverflow.com/questions/23723364/windows-7-make-is-not-recognized-as-an-internal-or-external-command-operabl
