class Object {
  public:
    
    // generate hash based on memory address
    size_t hash() {
      return (size_t)this;
    };

    // compare equality based on hash of two Object
    virtual bool equals(Object* obj) {
      return hash() == obj->hash();
    };
};
