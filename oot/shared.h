#ifndef __Z64OVL_OOT_SHARED_H__
#define __Z64OVL_OOT_SHARED_H__

/* relative offsets that remain the same between versions */

#define Z64GL_INTERFACE_ON          ((Z64GL_SAVE_CONTEXT) + 0x135F) /* byte */
#define Z64GL_CUTSCENE_PLAY_SCRIPT  ((Z64GL_SAVE_CONTEXT) + 0x1414) /* byte */
#define Z64GL_IS_NIGHT              ((Z64GL_SAVE_CONTEXT) + 0x0010) /* u32, 0 = day, 1 = night */
#define Z64GL_PAUSEPLAYER           (Z64GL_CODE + Z64GL_CODE_PAUSEPLAYER)

#endif /* __Z64OVL_OOT_SHARED_H__ */
