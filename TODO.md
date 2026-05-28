- [ ] Implementazione scheletro del programma e funzionamento
- [ ] Divisione dei compiti rispetto alle varie translational units
---
## Program flow
```mermaid
sequenceDiagram
    participant Config
    participant Generator
    participant Calculator
    participant Log
    participant View

    Config->>Generator: read parameters
    Generator->>Calculator: generate objects
    Calculator->>Log: write data
    Calculator->>View: display info
```

## TODO
simulation.hpp - Metodi fondamentali:
- energia potenziale (Da aggiustare!)
- quantità di moto totale
- momento angolare totale
- eventuale stampa/salvataggio dati
- rappresentazione grafica con SFML
- valutazione corretteza dati
- randomi input di dati
