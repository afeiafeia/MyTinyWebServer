//Proxy Class代理类，它允许完成一些难以完成的事情：
//（1）多维数组的实现
//（2）区分读和写
//（3）抑制隐式转换

//(1)实现多维数组
//用一层容器实现多维数组的实现：注意：vector<vector<>>也代表二维数组，但这是两层
#ifndef MY_PROXY_H
#define MY_PROXY_H
template<typename T>
class Array2D
{
    public:
    Array2D(T row,T cow);

    //Array2D(const Array2D &rhs);

    //Array2D& operator=(const Array2D &rhs);

    ~Array2D();

    template<typename T1>
    class Array1D
    {
        public:
        Array1D(int cow)
        {
            m_data = new T[cow];
        }
        T& operator[](int index);
        const T& operator[](int index)const;

        ~Array1D()
        {
            if (m_data)
            {
                delete []m_data;                /* code */
            }
            
        }
        private:
        T* m_data;
        int cow;
        Array2D& m_refArray2D;
        int m_index;
    };
    template<class T>
    T& Array1D<T>::operator[](int index)
    {
        return m_data[index];
    } 

    friend class Array1D;
    Array1D& operator[](int index);
    const Array1D& operator[](int index)const;



    private:
    Array1D* m_Array1d;
    int m_row;
    //int m_cow;

};

template<class T>
Array2D<T>::Array2D(T row,T cow)
{
    m_Array1d = ::operator new (sizeof(T)*row);
    void ptr = (void*)(m_Array1d);
    for (int i=0; i<row < sizeof(T)*row; i++;ptr+=sizeof(T))
    {
        ::new(ptr)Array1D(cow);
    }

    
}
template<class T>
typename Array2D<T>::Array1D<T>& Array2D<T>::operator[](int index)
{
    return m_Aray1d[index];
}



template<class T>
Array2D<T>::~Array2D()
{
    for (size_t i = 0; i < m_row; i++)
    {
        m_Array1d[i]->~Array1D();
    }
    
}


//(2)区分读和写





#endif//MY_PROXY_H