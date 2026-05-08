# Montreal Potholes Map - Application Wt

Une application web simple utilisant le framework Wt pour afficher une carte interactive des nids-de-poule à Montréal.

## Prérequis

- Wt framework installé (avec support Leaflet)
- CMake
- Compilateur C++17

## Compilation

```bash
mkdir build
cd build
cmake ..
make
```

## Exécution

### Méthode simple (recommandée)
```bash
./run.sh
```

### Méthode manuelle
```bash
# Assurez-vous que les bibliothèques sont dans le PATH
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

# Lancez l'application
./potholes_app --http-address=0.0.0.0 --http-port=8080 --docroot=/usr/local/share/Wt/
```

Puis ouvrez votre navigateur à l'adresse `http://localhost:8080`

## Fonctionnalités

- Carte interactive centrée sur Montréal
- Couche de tuiles OpenStreetMap
- Marqueur exemple avec popup
- Interface responsive

## Structure du code

- `main.cpp` : Code principal de l'application
- `CMakeLists.txt` : Configuration de compilation
- `build/` : Répertoire de compilation (généré)

## Configuration Leaflet

L'application utilise les propriétés suivantes dans `wt_config.xml` (optionnel) :

```xml
<property name="leafletJSURL">https://unpkg.com/leaflet@1.5.1/dist/leaflet.js</property>
<property name="leafletCSSURL">https://unpkg.com/leaflet@1.5.1/dist/leaflet.css</property>
```

## Extension future

Cette application peut être étendue pour :
- Charger des données de nids-de-poule depuis une base de données
- Ajouter des marqueurs dynamiques
- Intégrer des filtres et recherches
- Ajouter des statistiques et visualisations
