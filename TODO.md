- [ ] Implementazione scheletro del programma e funzionamento
- [ ] Divisione dei compiti rispetto alle varie translational units
---
## Program flow
```mermaid
sequenceDiagram
    participant dotcom
    participant iframe
    participant viewscreen
    dotcom->>iframe: loads html w/ iframe url
    iframe->>viewscreen: request template
    viewscreen->>iframe: html & javascript
    iframe->>dotcom: iframe ready
    dotcom->>iframe: set mermaid data on iframe
    iframe->>iframe: render mermaid
```

```mermaid
sequenceDiagram
    participant configFile
    participant logFle
    participant viewscreen
    participant class_body
    participant random_method
    participant generation
    participant calculator

    config_file->>generation: read parameters
    class_body->>generation: define objects
    random_method->>generation: initialization of position and velocity
    generation->>calculator: complete objects ready for calculation
    calculator->>log_file: write position, velocity and energy
    calculator->>viewscreen: display informations
```