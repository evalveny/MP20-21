
class NombreRacional
{
public:
	NombreRacional() : m_numerador(0), m_denominador(0) {}
	NombreRacional(int numerador, int denominador) : m_numerador(numerador), m_denominador(denominador) {}
	void setNumerador(int numerador);
	void setDenominador(int denominador);
	int getNumerador() const;
	int getDenominador() const;
	bool esValid() const;
	void simplifica();
	NombreRacional suma(const NombreRacional b) const;
	NombreRacional multiplica(const NombreRacional b) const;
	NombreRacional resta(const NombreRacional b) const;
	NombreRacional divideix(const NombreRacional b) const;
private:
	int m_numerador;
	int m_denominador;

	int maximComuDivisor();
};

