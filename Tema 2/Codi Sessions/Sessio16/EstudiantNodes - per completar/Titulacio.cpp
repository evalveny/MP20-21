#include "Titulacio.h"


void Titulacio::eliminaPrimerEstudiant()
{
	// Guardar apuntador al primer element en un auxiliar

	// Modificar apuntador al primer element (al seg�ent element)

	// Alliberar el primer element(utilitzant l�apuntador auxiliar)


}

void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	// Crear nou node

	// Inicialitzar estudiant i posar-lo al node

	// Enlla�ar nou node amb el primer element

	// Modificar apuntador al nou element

}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	NodeEstudiant* aux = m_estudiants;
	NodeEstudiant* anterior = nullptr;

	// Recuperar apuntador a l'estudiant que volem eliminar
	// i a l'element anterior
	// Aplicar esquema de cerca per recuperar estudiant, pero
	// recuperar tambe apuntador a l'element anterior





	if (trobat)
	{
		// si element a eliminar diferent de primer
		// Enlla�ar element anterior amb el seguent

		// si element a eliminar es el primer
		// modificar apuntador a primer

		// Alliberar memoria de l'element eliminat
		

		m_nEstudiants--;
	}
	return trobat;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	<inicialitzar_seq��ncia>
	while (!(<final_seq��ncia>) && (!trobat))
	{
		<recuperar_estudiant_actual>
		if (< condicio_trobat)
			trobat = true;
		else
			<avan�ar_seq��ncia>
	}
	return trobat;

}