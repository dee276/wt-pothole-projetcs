#!/bin/bash

# On force le chemin des bibliothèques
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

# On lance depuis la racine pour que les chemins relatifs soient ok
# On ajoute l'option --show-stacktrace pour voir l'erreur réelle si ça crash
./build/potholes_app \
    --http-address=0.0.0.0 \
    --http-port=9090 \
    --docroot=. \
    --resources-dir=/usr/local/share/Wt/resources \
    --show-stacktrace