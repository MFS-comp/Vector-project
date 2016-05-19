template <class T> class Vector
{
    public:
        //types
        typedef T  value_type;
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef unsigned size_type;

    private:
        size_type elemcount,space;
        T* arr;
        const static size_type memory_chunk = 8;

    public:
        //constructors and destructor
        Vector():elemcount(0),space(0),arr(new T[0]){}
       ~Vector() { delete [] arr;}
        explicit Vector (size_type nelems): elemcount(nelems), space(nelems)
        {
            arr = new T[nelems];
            for (size_type i = 0; i < nelems; ++i)
                arr[i] = 0;
        }

        //returning basic properties
        size_type size()
        {
            return elemcount;
        }
        size_type capacity()
        {
            return space;
        }
        size_type free_capacity()
        {
            return space-elemcount;
        }
        
        //memory manipulation
        void reserve (size_type newspace)
        {
            if (newspace <= space)
                return;
            T* newarr = new T[newspace];
            for (size_type i = 0; i < newspace; ++i)
                newarr[i] = arr[i];
            arr = newarr;
            space = newspace;
        }
        void resize (size_type newsize)
        {
            if (newsize == elemcount)
                return;
            T* newarr = new T[newsize];
            for (size_type i = 0; i < elemcount; ++i)
                newarr[i] = arr[i];
            delete [] arr;
            arr = newarr;
            elemcount = newsize;
            space = newsize;
        }
        void push_back (const T& newvalue)
        {
            if (space == elemcount)
                reserve(space*2);
            if (space == 0)
                reserve(memory_chunk);
            arr[elemcount] = newvalue;
            ++elemcount;
        }
        
        //memory access
        iterator begin ()
        {
            return arr;
        }
        const_iterator begin () const
        {
            return arr;
        }
        iterator end ()
        {
            return arr+elemcount;
        }
        const_iterator end () const
        {
            return arr+elemcount;
        }
        
        //operators
        T& operator[](size_type i)
        {
            return arr[i];
        }
        const T& operator[](size_type i) const
        {
            return arr[i];
        }

};
