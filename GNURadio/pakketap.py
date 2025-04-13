#!/usr/bin/env python3
# Kjør med: python3 pakketap.py <filnavn>

import sys

def tell_pakketap(filnavn):
    mottatte_pakker = set()

    try:
        with open(filnavn, "r") as f:
            for linje in f:
                linje = linje.strip()
                if "Pakke" in linje:
                    try:
                        nr = int(linje.split("Pakke")[1])
                        mottatte_pakker.add(nr)
                    except:
                        continue
    except FileNotFoundError:
        print(f"Finner ikke fila: {filnavn}")
        return

    if not mottatte_pakker:
        print("Ingen pakker funnet.")
        return

    første = min(mottatte_pakker)
    siste = max(mottatte_pakker)
    forventet = siste - første + 1
    mottatt = len(mottatte_pakker)
    tapte = forventet - mottatt

    print(f"Første pakke    : {første}")
    print(f"Siste pakke     : {siste}")
    print(f"Forventet pakker etter lås: {forventet}")
    print(f"Mottatt pakker  : {mottatt} ({mottatt / forventet * 100:.2f}%)")
    print(f"Tapte pakker    : {tapte} ({tapte / forventet * 100:.2f}%)")

    if tapte > 0:
        mangler = sorted(set(range(første + 1, siste)) - mottatte_pakker)
        print(f"Første 10 tapte pakker: {mangler[:10]}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Bruk: python3 pakketap.py <filnavn>")
    else:
        tell_pakketap(sys.argv[1])

