- [ ] Implementazione scheletro del programma e funzionamento
- [ ] Divisione dei compiti rispetto alle varie translational units
---
## Program flow
graph TD
    A[Inizio] --> B{Decisione?}
    B -->|Sì| C[Azione 1]
    B -->|No| D[Azione 2]
    C --> E[Fine]
    D --> E   