#include "Navegador.h"

void Navegador::anarEnrere()
{
	if (!m_paginesVisitades.empty())
	{
		m_paginesPerVisitar.push(m_paginaActual);
		m_paginaActual = m_paginesVisitades.top();
		m_paginesVisitades.pop();
	}
}

void Navegador::anarEndavant()
{
	if (!m_paginesPerVisitar.empty())
	{
		m_paginesVisitades.push(m_paginaActual);
		m_paginaActual = m_paginesPerVisitar.top();
		m_paginesPerVisitar.pop();
	}
}

void Navegador::visitarNovaPagina(const string &url)
{
	m_paginesVisitades.push(m_paginaActual);
	m_paginaActual= url;
	while (!m_paginesPerVisitar.empty())
		m_paginesPerVisitar.pop();
}


