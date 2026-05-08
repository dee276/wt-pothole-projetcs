#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLeafletMap.h>
#include <Wt/WText.h>
#include <Wt/Json/Object.h>

class PotholeApp : public Wt::WApplication {
public:
    PotholeApp(const Wt::WEnvironment& env);

private:
    void createMap(Wt::WContainerWidget *parent);
};

PotholeApp::PotholeApp(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    setTitle("Montreal Potholes Map");

    auto container = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
    container->addWidget(std::make_unique<Wt::WText>("<h1>Carte des Nids-de-Poule à Montréal</h1>"));

    createMap(container);
}

void PotholeApp::createMap(Wt::WContainerWidget *parent) {
    // Création du widget de carte
    auto map = parent->addWidget(std::make_unique<Wt::WLeafletMap>());

    // Indispensable pour l'affichage
    map->resize(800, 600);

    // Configuration des tuiles OpenStreetMap
    Wt::Json::Object tileOptions;
    tileOptions["maxZoom"] = 19;
    tileOptions["attribution"] = "&copy; <a href=\"https://www.openstreetmap.org/copyright\">OpenStreetMap</a> contributors";
    
    map->addTileLayer("https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png", tileOptions);

    // Centrage sur Montréal
    Wt::WLeafletMap::Coordinate montrealCenter(45.5017, -73.5673);
    map->panTo(montrealCenter);
    map->setZoomLevel(12);

    // Marqueur de test
    auto markerText = std::make_unique<Wt::WText>("Centre-ville de Montréal");
    auto marker = std::make_unique<Wt::WLeafletMap::WidgetMarker>(montrealCenter, std::move(markerText));
    marker->addPopup(std::make_unique<Wt::WLeafletMap::Popup>("Bienvenue à Montréal !"));
    map->addMarker(std::move(marker));
}

std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env) {
    return std::make_unique<PotholeApp>(env);
}

int main(int argc, char **argv) {
    return Wt::WRun(argc, argv, &createApplication);
}