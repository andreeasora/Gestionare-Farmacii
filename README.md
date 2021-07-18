# Gestionare Farmacii
Proiect Programare Orientată pe Obiecte - Gestionare Farmacii

Se dorește implementarea unei aplicații OOP care să permită gestionarea activității unor farmacii aparținând proprietarului X. 
Pentru fiecare farmacie se cunoaște cel puțin denumirea, numărul de angajați și profiturile pe fiecare luna. Farmaciile pot fi și online. 
În acest caz se cunoaște doar adresa web, numărul de vizitatori și discountul utilizat. Structura de date: vector.

**Cerința suplimentară:**
Să se construiască clasa template GestionareFarmacii care să conțină informații despre diversele tipuri de farmacii. Clasa conține indexul farmaciei (incrementat automat la adăugarea unei noi file), id-ul lanțului (constant) și o structură de obiecte, alocată dinamic. 
Să se supraîncarce operatorul += pentru inserarea unei noi farmacii online în structură. Să se construiască o specializare pentru tipul Farmacie_online care să conțină și să afișeze doar numărul total de vizitatori ai farmaciilor online.
