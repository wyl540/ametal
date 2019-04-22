/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZMF159 SPI �û������ļ�
 * \sa am_hwconf_zmf159_spi_int.c
 *
 * \internal
 * \par Modification history
 * - 1.00 18-08-08  htf, first implementation.
 * \endinternal
 */

#include "ametal.h"
#include "am_zmf159.h"
#include "am_zlg_spi_poll.h"
#include "am_gpio.h"
#include "hw/amhw_zlg_spi.h"
#include "am_clk.h"

/**
 * \addtogroup am_if_src_hwconf_zmf159_spi_poll
 * \copydoc am_hwconf_zmf159_spi_poll.c
 * @{
 */

/** \brief SPI1 ƽ̨��ʼ�� */
static void __zlg_plfm_spi1_poll_init (void)
{
    am_gpio_pin_cfg(PIOA_5, PIOA_5_SPI1_SCK  | PIOA_5_AF_PP);
    am_gpio_pin_cfg(PIOA_6, PIOA_6_SPI1_MISO | PIOA_6_INPUT_FLOAT);
    am_gpio_pin_cfg(PIOA_7, PIOA_7_SPI1_MOSI | PIOA_7_AF_PP);

    am_clk_enable(CLK_SPI1);
}

/** \brief ���SPI1 ƽ̨��ʼ�� */
static void __zlg_plfm_spi1_poll_deinit (void)
{

    /* �ͷ�����Ϊ����ģʽ */
    am_gpio_pin_cfg(PIOA_5, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOA_6, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOA_7, AM_GPIO_INPUT);

    am_clk_disable(CLK_SPI1);
}

/**
 * \brief SPI1 �豸��Ϣ
 */
const  struct am_zlg_spi_poll_devinfo  __g_spi1_poll_devinfo = {
    ZMF159_SPI1_BASE,                   /**< \brief SPI1�Ĵ���ָ�� */
    CLK_SPI1,                           /**< \brief ʱ��ID�� */
    PIOA_7_SPI1_MOSI | PIOA_7_AF_PP,    /**< \brief SPI1���ñ�ʶ */
    PIOA_7,                             /**< \brief MOSI���ź� */
    __zlg_plfm_spi1_poll_init,           /**< \brief SPI1ƽ̨��ʼ������ */
    __zlg_plfm_spi1_poll_deinit          /**< \brief SPI1ƽ̨���ʼ������ */
};

/** \brief SPI1 �豸ʵ�� */
static am_zlg_spi_poll_dev_t __g_spi1_poll_dev;

/** \brief SPI1 ʵ����ʼ�������SPI��׼������ */
am_spi_handle_t am_zmf159_spi1_poll_inst_init (void)
{
    return am_zlg_spi_poll_init(&__g_spi1_poll_dev, &__g_spi1_poll_devinfo);
}

/** \brief SPI1 ʵ�����ʼ�� */
void am_zmf159_spi1_poll_inst_deinit (am_spi_handle_t handle)
{
    am_zlg_spi_poll_deinit(handle);
}

/*******************************************************************************/

/** \brief SPI2 ƽ̨��ʼ�� */
static void __zlg_plfm_spi2_poll_init (void)
{
    am_gpio_pin_cfg(PIOB_13, PIOB_13_SPI2_SCK | PIOB_13_INPUT_FLOAT);
    am_gpio_pin_cfg(PIOB_14, PIOB_14_SPI2_MISO | PIOB_14_AF_PP);
    am_gpio_pin_cfg(PIOB_15, PIOB_15_SPI2_MOSI  | PIOB_15_AF_PP);

    am_clk_enable(CLK_SPI2);
}

/** \brief ��� SPI2 ƽ̨��ʼ�� */
static void __zlg_plfm_spi2_poll_deinit (void)
{
    am_gpio_pin_cfg(PIOB_13, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOB_14, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOB_15, AM_GPIO_INPUT);

    am_clk_disable(CLK_SPI2);
}
/**
 * \brief SPI2 �豸��Ϣ
 */
const  struct am_zlg_spi_poll_devinfo  __g_spi2_poll_devinfo = {
    ZMF159_SPI2_BASE,                      /**< \brief SPI2 �Ĵ���ָ�� */
    CLK_SPI2,                              /**< \brief ʱ�� ID �� */
    PIOB_14_SPI2_MISO | PIOB_14_AF_PP,     /**< \brief SPI2 ���ñ�ʶ */
    PIOB_14,                               /**< \brief MOSI ���ź� */
    __zlg_plfm_spi2_poll_init,              /**< \brief SPI2 ƽ̨��ʼ������ */
    __zlg_plfm_spi2_poll_deinit             /**< \brief SPI2 ƽ̨���ʼ������ */
};

/** \brief SPI2 �豸ʵ�� */
static am_zlg_spi_poll_dev_t __g_spi2_poll_dev;

/** \brief SPI2 ʵ����ʼ������� SPI ��׼������ */
am_spi_handle_t am_zmf159_spi2_poll_inst_init (void)
{
    return am_zlg_spi_poll_init(&__g_spi2_poll_dev, &__g_spi2_poll_devinfo);
}

/** \brief SPI2 ʵ�����ʼ�� */
void am_zmf159_spi2_poll_inst_deinit (am_spi_handle_t handle)
{
    am_zlg_spi_poll_deinit(handle);
}

/*******************************************************************************/

/** \brief SPI3 ƽ̨��ʼ�� */
static void __zlg_plfm_spi3_poll_init (void)
{
    am_gpio_pin_cfg(PIOC_10, PIOC_10_SPI3_SCK | PIOC_10_INPUT_FLOAT);
    am_gpio_pin_cfg(PIOC_11, PIOC_11_SPI3_MISO | PIOC_11_AF_PP);
    am_gpio_pin_cfg(PIOC_12, PIOC_12_SPI3_MOSI  | PIOC_12_AF_PP);

    am_clk_enable(CLK_SPI3);
}

/** \brief ��� SPI3 ƽ̨��ʼ�� */
static void __zlg_plfm_spi3_poll_deinit (void)
{
    am_gpio_pin_cfg(PIOC_10, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOC_11, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOC_12, AM_GPIO_INPUT);

    am_clk_disable(CLK_SPI3);
}
/**
 * \brief SPI3 �豸��Ϣ
 */
const  struct am_zlg_spi_poll_devinfo  __g_spi3_poll_devinfo = {
    ZMF159_SPI3_BASE,                      /**< \brief SPI2 �Ĵ���ָ�� */
    CLK_SPI3,                              /**< \brief ʱ�� ID �� */
    PIOC_11_SPI3_MISO | PIOC_11_AF_PP,     /**< \brief SPI2 ���ñ�ʶ */
    PIOC_11,                               /**< \brief MOSI ���ź� */
    __zlg_plfm_spi3_poll_init,              /**< \brief SPI2 ƽ̨��ʼ������ */
    __zlg_plfm_spi3_poll_deinit             /**< \brief SPI2 ƽ̨���ʼ������ */
};

/** \brief SPI3 �豸ʵ�� */
static am_zlg_spi_poll_dev_t __g_spi3_poll_dev;

/** \brief SPI3 ʵ����ʼ������� SPI ��׼������ */
am_spi_handle_t am_zmf159_spi3_poll_inst_init (void)
{
    return am_zlg_spi_poll_init(&__g_spi3_poll_dev, &__g_spi3_poll_devinfo);
}

/** \brief SPI3 ʵ�����ʼ�� */
void am_zmf159_spi3_poll_inst_deinit (am_spi_handle_t handle)
{
    am_zlg_spi_poll_deinit(handle);
}

/**
 * @}
 */

/* end of file */