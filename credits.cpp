#include <fstream> //lecture/écriture
#include <iostream>
#include <string>
#include <cstdlib> // atoi ---> transformer un string en int
#include <ctime> // compte à rebours
using namespace std;
#include "fonctions.cpp"


int main()
{
	bool quitter=false; //condition de la boucle while principale
	clear(); //nettoie le terminal
	int suppression(0),points(0),coeffAlgebre(10),coeffCalculus(8),coeffAlgo(3),coeffBinaire(2),coeffPhysique(7);
	int ecriture_credit,choix_menu,choix_boutique,choix_matiere,occExo;
	string credits;

	while(!quitter)
	{
		//à chaque tour de boucle, on affiche le nombre de crédits disponible. On récuppère la valeur dans "credits"
		credits=lire();
		cout<<"Vous avez "<<credits<<" crédits.";




		//Ce bloc ajoute le (+) ou le (-) quand la valeur de credits change
		if(suppression!=0)
		{
			cout<<" (";
			if(-1*suppression>0)
				cout<<"+";
			cout<<-1*suppression<<")";
			suppression=0;
		}
		if(points!=0)
		{
			cout<<" (+"<<points<<")";
			points=0;
		}


		//Interface principal avec l'utilisateur
		cout<<endl<<"Que voulez vous faire ? "<<endl<<endl;
		cout<<"0.Quitter"<<endl;
		cout<<"1.Ajouter des crédits"<<endl;
		cout<<"2.Supprimer des crédits"<<endl;
		cout<<"3.Boutique"<<endl;
		cout<<endl<<"Entrez le nombre de votre choix : ";
		cin>>choix_menu;



		//On vérifie que le choix existe
		if(choix_menu<0 || choix_menu>4)
			cout<<"Votre choix n'existe pas. Veuillez recommencer ! "<<endl;


		//0 <=> quitter la boucle (et donc le programme)
		else if(choix_menu==0)
			{
				clear();
				quitter=true;
			}


		//1 <=> Afficher le choix des matières
		else if(choix_menu==1)
		{
			clear();

			//Interface des choix de matière
			cout<<"Choisissez la matière--"<<endl<<endl;
			cout<<"1.Algèbre"<<endl;
			cout<<"2.Calculus"<<endl;
			cout<<"3.Algorithmie"<<endl;
			cout<<"4.Binaire au Web"<<endl;
			cout<<"5.Physique"<<endl;
			cout<<endl<<"Votre choix : ";
			cin>>choix_matiere;

			//vérification
			if(choix_matiere<1 || choix_matiere>5)
			{
				clear();
				cout<<"Entrée non valide.\n";
			}

			//Si la saisie est bonne, on enregistre le nombre d'exercice dans la matière concernée
			else
			{
				cout<<"Nombre d'exercice : ";
				cin>>occExo;
				if(occExo<1)
				{
					clear();
					cout<<"Soyons réaliste.\n";
				}
				else
				{
					//On stocke le résultat final dans points
					switch(choix_matiere)
					{
						//Algèbre
						case 1:                       
						points=coeffAlgebre*occExo;
						break;

						//Calculus
						case 2:                       
						points=coeffCalculus*occExo;
						break;

						//Algorithmie
						case 3:                       
						points=coeffAlgo*occExo;      
						break;

						//Binaire au Web
						case 4:                      
						points=coeffBinaire*occExo;
						break;

						//Physique
						case 5:                      
						points=coeffPhysique*occExo;
						break;

					}

					clear();
					ecrire(points+(atoi(credits.c_str())));
				}
			}

		}


		//2 <=> suppression de crédits
		else if(choix_menu==2)
		{
			clear();
			credits=lire();
			cout<<"Vous avez "<<credits<<" crédits. Combien voulez-vous en enlever ? ";
			cin>>suppression;
			clear();
			if(suppression!=0)
				ecrire((atoi(credits.c_str()))-suppression);
		}


		//3 <=> Boutique
		else if(choix_menu==3)
		{
			clear();

			//Interface de la boutique
			cout<<"Que voulez vous acheter ?"<<endl<<endl;
			cout<<"0.Quitter la boutique"<<endl;
			cout<<"1.Acheter 1 heure de jeux --> (75 crédits)"<<endl<<endl;
			cout<<"Votre choix : ";
			cin>>choix_boutique;


			//NB : Toutes les valeurs autre que 1 quitteront la boutique
			if(choix_boutique==1)
			{
				credits=lire();
				if((atoi(credits.c_str()))>74)
				{
					clear();
					ecrire((atoi(credits.c_str()))-75);
					cout<<"Le compte a rebours a commencé."<<endl;
					rebour(65);
				}
				else
					cout<<"ERREUR ! Vous n'avez pas assez de crédits !";

			}
			clear();


		}
		else if(choix_menu==42)
			rebour(10);
	}



	return 0;
}
