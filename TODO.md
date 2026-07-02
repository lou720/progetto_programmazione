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
- quantità di moto totale
- momento angolare totale
- eventuale stampa/salvataggio dati
- valutazione corretteza dati
- randomi input di dati
