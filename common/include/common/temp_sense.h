#ifndef TOKEN_COMMON_TEMP_H
#define TOKEN_COMMON_TEMP_H


namespace common {

class Temp_Sense {
public:
    Temp_Sense() = default;
    virtual ~Temp_Sense() = default;
    Temp_Sense(const Temp_Sense &) = default;
    Temp_Sense(Temp_Sense &&) = default;
    Temp_Sense & operator=(const Temp_Sense &) = default;
    Temp_Sense & operator=(Temp_Sense &&) = default;

	virtual void Read_Temp_Register(int *) noexcept = 0;
    virtual void write_register() noexcept = 0;
	virtual void Init_Temp_Sensor() noexcept = 0;
};

} // namespace common

#endif
