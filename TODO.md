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

## Obiettivo: figura 8
file configurazione
TU lettura dati

TU corpi

TU generazione corpi

TU calcolo posizione

TU view
---