#ifndef TOKEN_COMMON_DISP_H
#define TOKEN_COMMON_DISP_H

namespace common {

class Display_Seg {
public:
    Display_Seg() = default;
    virtual ~Display_Seg() = default;
    Display_Seg(const Display_Seg &) = default;
    Display_Seg(Display_Seg &&) = default;
    Display_Seg & operator=(const Display_Seg &) = default;
    Display_Seg & operator=(Display_Seg &&) = default;

   	virtual void display_val(unsigned char,int *) noexcept = 0;

};

} // namespace nucleo_f103rb

#endif
