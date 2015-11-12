// BiMatrix.tcc

namespace linear
{

	template<typename RowMatrixType>
	const typename BiMatrix<RowMatrixType>::row_type& BiMatrix<RowMatrixType>::GetColumn(uint index) const
	{
		return _transp.GetRow(index);
	}

	template<typename RowMatrixType>
	void BiMatrix<RowMatrixType>::Gevm(const double* p_x, double* p_y, double alpha, double beta) const
	{
		_transp.Gemv(p_x, p_y, alpha, beta);
	}
}