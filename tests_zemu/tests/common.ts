import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')
const APP_PATH_SP = Resolve('../app/output/app_s2.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
]

export const txBasic =
  '060000036fa3fc0b5aa41e86dc2ce5cb3a28cb322ad401b017c2232949f009697dce7e0b63ce64c10c05d503ae11030003d20296492e00000001000000742a2ca70c2fda6cee4f8df98d64c4c670a052d9568058982dad9d5a7a135c5b742a2ca70c2fda6cee4f8df98d64c4c670a052d9568058982dad9d5a7a135c5b'

export const txNomination =
  '080508002229b353a1b15bf4743ff12fb2c660ff8edf888f6f89bb11fb9878a57435034e00240eb98ac9d5823076f4005dfade11fadd72fcf2c9b902401f882ba926d0170ad503006d0f2e00000001000000742a2ca70c2fda6cee4f8df98d64c4c670a052d9568058982dad9d5a7a135c5b742a2ca70c2fda6cee4f8df98d64c4c670a052d9568058982dad9d5a7a135c5b'
