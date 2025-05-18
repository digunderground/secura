###########################################################################
# Secura - Graflex Lightsaber Chassis - RELEASE
###########################################################################

PLEASE READ ANY/ALL .MD FILES BEFORE WASTING $$ ON PRINTS YOU DONT NEED
we are working on updates to these .MD files 

###########################################################################
##  KNOWN ISSUES - This is a WIP!!! 
###########################################################################

- the 33mm speaker (Shtok titan) requires quite a bit of thinning for the enclosure. This likely CANNOT be printed via FDM/SLA/SLS and needs to be done via SLM + nail-biting sanding.
- for FDM/SLA/SLS: you will need to merge the main battery chassis and positive (top) isolation terminal as a single print 

###########################################################################
##  Status
###########################################################################

Current Progress:
- OFFICIAL RELEASE with all assembly edits - 20250518

Past: 
- base F3d files uploaded for closed beta - 20250325
- uploaded STEP Files for non-f360 users - 20250327
- initial open source license in place - 20250325
- WIP BOM file in place for needed parts - 20250325
- pushed STL variants for people without Fusion360 - 20250325
- pushed DXF for laser cut metal pieces - 20250325
- Personal install complete - making some minor updates and will pull the project out of beta.- 20250503
- base proffie config is done and being finalized with wiring diagram - 20250503
- bespoke stand for graflex + chassis - in testing
- added a free open source saber stand for chassis and hilt

TODO:
- Update WIP BOM: tools needed, reformat doc
- direct links to purchasable carts for 3d print services and metal cutting services.
- Find contributor for CFX holder and configs
- Write or collaborate for install manual + exploded drawings etc


---
Lightsaber Render:

![secura-render](https://github.com/user-attachments/assets/7858f8eb-e6d5-46d7-9ce5-63f1d3020e00)

Lightsaber Stand Render: 

![Secura Stand-filled](https://github.com/user-attachments/assets/cd0e52e9-e7fb-4bac-8f0d-4c87d61e0846)
https://github.com/digunderground/secura/tree/main/STL/Secura-stand

### The intention is to print this in SLM metal using services like:
- 316L best price: https://jlc3dp.com/
- Aluminium and other metals: https://craftcloud3d.com/

### Laser Cut metal parts have been tested from:
- https://sendcutsend.com/

### Should you choose to print this using FDM or SLA or SLS, see the notes below: 
For FDM:
- the finished product WILL lack strength in the layer direction
- you WILL lose some of the detail
- we recommend tree supports where necessarry
- you will need to merge some parts into one (positive terminal isolation) and potentially use alternate parts
- you will lose the chassis being a common ground 

For SLA:
- we recommend a 50/50 mixture of Siraya Tech Tenacious Flex and an "ABS Like Resin" - SUNLU works well
- SLA is weaker than most FDM, but has unidirectional strength
- you will need to merge some parts into one (positive terminal isolation) and potentially use alternate parts
- you will lose the chassis being a common ground 

For SLS:
- we recommend this over SLA and FDM, but still inferior to metal
- you will need to merge some parts into one (positive terminal isolation) and potentially use alternate parts
- this is the best budget option if metal is not an option for you.
- you will lose the chassis being a common ground 

###########################################################################
##  License information: 
###########################################################################

Secura Lightsaber Chassis © 2024 by PyxisVeritas LLC. is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International 

CC BY-NC-SA 4.0
This license requires that reusers give credit to the creator. 
It allows reusers to distribute, remix, adapt, and build upon the material in any medium or format, for noncommercial purposes only. 
If others modify or adapt the material, they must license the modified material under identical terms.

Additional permissions granted to Installers, Makers, Educational usage, and STEM - details available in:
https://github.com/digunderground/secura/blob/main/LICENSE

BY: Credit must be given to the creator.

NC: Only noncommercial use of your work is permitted.
Noncommercial means not primarily intended for or directed towards commercial advantage or monetary compensation.

SA: Adaptations must be shared under the same terms.

License Deed: 
https://creativecommons.org/licenses/by-nc-sa/4.0/

License Legal: 
https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode.en

