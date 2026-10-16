# Jade Larouche

## Les fonctionnalités que j'ai choisi d'implémenter : 
- La numérotation automatique des ID utilisateurs.
- Tri des résultats par titre, auteur pour l'affichage (utilisation de la fonction de tri de la STL).
- Création de la journalisation des sessions

### Question 1 : C++
La création de la journalisation est la fonctionnalité que j'ai trouvé le plus dure à coder.
Je dirai que cela m'a mêlé de faire mon filemanager et mon main.cpp en même temps.
Cette méthode m'a pris beaucoup de temps a régler. J'ai du ajuster que si le fichier n'existe pas de le créer 
et surtout d'aller chercher et de l'ajouter au bon endroit. Je devais aussi ajouter l,erreur que si on 
ne trouve pas le dossier la il y a une erreur.

```cpp
void FileManager::logActivity(const string& action, const string& details) {
    // Trouver le dossier où se trouvent les fichiers de données
    filesystem::path dataDir = filesystem::path(booksFileName).parent_path();
    filesystem::path logPath = dataDir / "journal.txt";

    ofstream logFile(logPath, ios::app);
    if (!logFile.is_open()) {
        cout << "Erreur : Impossible d'ouvrir le fichier de journalisation.\n";
        return;
    }

    // Obtenir la date et l'heure actuelles
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

    // Écrire la ligne dans le journal
    logFile << buffer << " - [ " << action << " ] " << details << "\n";
    logFile.close();
}
```

Ensuite dans le `main.cpp`, je dois ajouter la ligne pour la méthode qui fait journalisation dans les cases.
Donc par exemple, je devais avoir la date, l'heure, l'action qui a été fait, le titre, l'auteur, le isbn et la disponibilité

```cpp
fileManager.logActivity("AJOUT LIVRE", title + "|" + author + "|" + isbn + "|" + "1|");
```

### Question 2 : Options de développement possible
Clairement que le premier problème rencontré serai les `fichiers.txt` en tant que base de donnée,
donc c'est sur que une base de données SQL serait beaucoup plus adaptée. Les systèmes comme MySQL
permettent d'indexer les champs important (titre, auteur, isbn) et d'effectuer des recherche rapides
même sur des volumes plus grand. J'ai recherché et vue que le C++ pourrait s'interfacer avec la base 
de données via un connecteur, en remplaçant aussi les opérations de lecture/écriture par des requêtes SQL.
Cette solution offrirait une meilleure performance et une meilleure fiabilité pour un bibliothèque avec des
millions de livres futures.

#### Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

#### Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`