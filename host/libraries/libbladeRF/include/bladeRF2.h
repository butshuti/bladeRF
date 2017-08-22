/**
 * @file bladeRF2.h
 *
 * @brief bladeRF2-specific API
 *
 * Copyright (C) 2013-2017 Nuand LLC
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */
#ifndef BLADERF2_H_
#define BLADERF2_H_

/**
 * @defgroup BLADERF2 bladeRF2-specific API
 *
 * These functions are thread-safe.
 *
 * @{
 */

/**
 * @defgroup FN_BLADERF2_LOW_LEVEL Low-level accessors
 *
 * In a most cases, higher-level routines should be used. These routines are
 * only intended to support development and testing.
 *
 * Use these routines with great care, and be sure to reference the relevant
 * schematics, data sheets, and source code (i.e., firmware and hdl).
 *
 * Be careful when mixing these calls with higher-level routines that manipulate
 * the same registers/settings.
 *
 * These functions are thread-safe.
 *
 * @{
 */

/**
 * Read an AD9361 register
 *
 * @param       dev         Device handle
 * @param[in]   address     AD9361 register address
 * @param[out]  val         Register value
 *
 * @return 0 on success, value from \ref RETCODES list on failure
 */
API_EXPORT
int CALL_CONV bladerf_ad9361_read(struct bladerf *dev,
                                  uint16_t address,
                                  uint8_t *val);
/**
 * Write an AD9361 register
 *
 * @param       dev         Device handle
 * @param[in]   address     AD9361 register address
 * @param[in]   val         Value to write to register
 *
 * @return 0 on success, value from \ref RETCODES list on failure
 */
API_EXPORT
int CALL_CONV bladerf_ad9361_write(struct bladerf *dev,
                                   uint16_t address,
                                   uint8_t val);

/**
 * Read value from ADF4002 Phase Detector/Frequency Synthesizer
 *
 * Reference:
 * http://www.analog.com/media/en/technical-documentation/data-sheets/ADF4002.pdf
 *
 * The address is interpreted as the control bits (DB1 and DB0) used to write
 * to a specific latch.
 *
 * Note that val is shifted right by 2 bits, relative to the data sheet's latch
 * map. val(21 downto 0) = DB(23 downto 2)
 *
 * @param       dev         Device handle
 * @param[in]   address     ADF4002 latch address
 * @param[out]  val         Value to read from ADF4002
 *
 * @return 0 on success, value from \ref RETCODES list on failure
 */
API_EXPORT
int CALL_CONV bladerf_adf4002_read(struct bladerf *dev,
                                   uint8_t address,
                                   uint32_t *val);

/**
 * Write value to ADF4002 Phase Detector/Frequency Synthesizer
 *
 * Reference:
 * http://www.analog.com/media/en/technical-documentation/data-sheets/ADF4002.pdf
 *
 * The address is interpreted as the control bits (DB1 and DB0) used to write
 * to a specific latch.
 *
 * Note that val is shifted right by 2 bits, relative to the data sheet's latch
 * map. val(21 downto 0) = DB(23 downto 2)
 *
 * @param       dev         Device handle
 * @param[in]   address     ADF4002 latch address
 * @param[in]   val         Value to write to ADF4002
 *
 * @return 0 on success, value from \ref RETCODES list on failure
 */
API_EXPORT
int CALL_CONV bladerf_adf4002_write(struct bladerf *dev,
                                    uint8_t address,
                                    uint32_t val);

/** @} (End of FN_BLADERF2_LOW_LEVEL) */

/** @} (End of BLADERF2) */

#endif /* BLADERF2_H_ */
